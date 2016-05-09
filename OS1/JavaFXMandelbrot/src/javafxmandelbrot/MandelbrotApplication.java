package javafxmandelbrot;

import java.util.ArrayList;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Button;
import javafx.scene.control.ChoiceBox;
import javafx.scene.input.MouseButton;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.stage.Stage;



public class MandelbrotApplication extends Application implements EventHandler<ActionEvent> {

    final static int X_PIXEL = 450; //630 change this value if you have a slow (or fast...) laptop
    final static int Y_PIXEL = X_PIXEL;
    final static int XY_SIZE = X_PIXEL * Y_PIXEL;
    final static double STEP = 2.3 / X_PIXEL;
    private Button btnStart;
    private Button btnStop;
    private Button btnClear;
    private Button btnSim;
    private ChoiceBox<Integer> cboxGrid;
    private Canvas canvas;
    private GraphicsContext gc;
    private PixelManager pixelManager;
    private TileFactory tileFactory;
    private ArrayList<Thread> threads;
    
    private ExecutorService pool;
    private CountDownLatch doneSignal;
    private int cores; //Save the number of cores of the current cpu
    
    @Override
    public void start(Stage primaryStage) {
           
        btnStart = new Button("start");
        btnStop = new Button("stop");
        btnClear = new Button("clear");
        btnSim = new Button("sim");
        cboxGrid = new ChoiceBox<>(FXCollections.observableArrayList(1, 2, 3, 4, 5, 6, 7, 8, 9));
        cboxGrid.getSelectionModel().selectFirst();
        btnStart.setOnAction(this);
        btnStop.setOnAction(this);
        btnClear.setOnAction(this);
        btnSim.setOnAction(this);
        threads = new ArrayList<>();

        primaryStage.setTitle("Mandelbrot");
        HBox root = new HBox();
        VBox vbox = new VBox();
        vbox.setSpacing(10);
        root.setSpacing(10);

        root.setPadding(new Insets(10, 10, 10, 10));
        vbox.setPadding(new Insets(10, 10, 10, 10));
        canvas = new Canvas(X_PIXEL, Y_PIXEL);
        canvas.addEventHandler(MouseEvent.MOUSE_CLICKED, new MouseEventHandler());
        gc = canvas.getGraphicsContext2D();
        tileFactory = new TileFactory (X_PIXEL, Y_PIXEL, -0.5, 0.0, STEP);

        cores = Runtime.getRuntime().availableProcessors();
        System.out.println("The number of core on this system is: " + cores);
        System.out.println("Start new thread pool of size " + cores);
        pool = Executors.newFixedThreadPool(cores); //First init
        
        initCanvas();

        root.getChildren().add(canvas);
        root.getChildren().add(vbox);
        vbox.getChildren().add(btnStart);
        vbox.getChildren().add(btnStop);
        vbox.getChildren().add(btnClear);
        vbox.getChildren().add(btnSim);
        vbox.getChildren().add(cboxGrid);

        primaryStage.setScene(new Scene(root));
        primaryStage.show();
        
        sim();
        
        btnStop.setDisable(true);
    }

    private void initCanvas() {
        // gray canvas with white lines indicating the tiles
        int nrofTiles, w, h;

        gc.setFill(Color.WHITE);
        gc.fillRect(0, 0, canvas.getWidth(), canvas.getHeight());
        gc.setLineWidth(1);
        gc.setFill(Color.GRAY);

        nrofTiles = Integer.parseInt(cboxGrid.getValue().toString());
        w = (int) canvas.getWidth() / nrofTiles;
        h = (int) canvas.getHeight() / nrofTiles;

        for (int i = 0; i < nrofTiles; i++) {
            for (int j = 0; j < nrofTiles; j++) {
                gc.fillRect(i * w, j * h, w - 1, h - 1);
            }
        }
    }

    private void sim() {

        pixelManager = new PixelManager(gc, XY_SIZE);
        System.out.println("sim-1 " + System.currentTimeMillis());

        for (int i = 0; i < X_PIXEL; i++) {
            for (int j = 0; j < Y_PIXEL; j++) {
                Pixel p = new Pixel(i, j, Color.rgb((i * 256) / X_PIXEL, (j * 256) / Y_PIXEL, 0));
                pixelManager.add(p);
            }
        }
        System.out.println("sim-2 " + System.currentTimeMillis());
        pixelManager.show();
        System.out.println("sim-3 " + System.currentTimeMillis());
    }

    @Override
    public void handle(ActionEvent t) {
        if (t.getSource() == btnStart) {
            startThreads();
        } else if (t.getSource() == btnStop) {
            stopThreads();
        } else if (t.getSource() == btnClear) {
            initCanvas();
        } else if (t.getSource() == btnSim) {
            sim();
        } else {
            System.out.println("unknown event: " + t.toString());
        }
    }
    
    private void stopThreads() {

        pool.shutdown();
        System.out.println("Thread pool stopped");
        btnStart.setDisable(false);
    }

    private void startThreads() {
        int nrofTiles;
      
        //Check if the pool it's not shutdown if the user press stop
        if(pool.isShutdown()){
            pool = Executors.newFixedThreadPool(cores);
        }
        
        pixelManager = new PixelManager(gc, XY_SIZE);
        initCanvas();

        nrofTiles = Integer.parseInt(cboxGrid.getValue().toString());
        
        //Set Latch depending on the pixel grid
        doneSignal = new CountDownLatch(nrofTiles * nrofTiles); 
        
        tileFactory.setNrofTiles(nrofTiles);
        threads.clear();

        for (int i = 0; i < nrofTiles; i++) {
            for (int j = 0; j < nrofTiles; j++) {
                Tile tile = tileFactory.createTile(i, j);
                Mandelbrot m = new Mandelbrot(tile, pixelManager, doneSignal);          
                pool.execute(m);               
            }
        }
        
        ThreadOverview threadOverview = new ThreadOverview();
        BtnThreadSwitch t = new BtnThreadSwitch();
        t.setName("Thread Button Switch");
        t.start();
        //Platform.runLater(t); The application freeze if i run the thread with this
        btnStart.setDisable(true);
        btnStop.setDisable(false);
    }

    class MouseEventHandler implements EventHandler<MouseEvent> {

        @Override
        public void handle(MouseEvent event) {
            System.out.println("mouse " + event.getX() + " " + event.getY() + " " + event.getButton());
            
            if (event.getButton() == MouseButton.PRIMARY) {
                tileFactory.zoomOut(event.getX(), event.getY());
            } else if (event.getButton() == MouseButton.SECONDARY) {
                tileFactory.zoomIn(event.getX(), event.getY());
            } else if (event.getButton() == MouseButton.MIDDLE) {
                tileFactory.pan(event.getX(), event.getY());
            } else {
                return;
            }
            
            startThreads();
        }
    }
    
    class BtnThreadSwitch extends Thread{
        
       @Override
       public void run(){
            
           try { 
               doneSignal.await(); 
               System.out.println("CountDownLatch 0, now i can toggle the button!");
               btnStart.setDisable(false);
               btnStop.setDisable(true);             
           } 
           catch (InterruptedException ex) {
           
           }
       }
    }
    
}
