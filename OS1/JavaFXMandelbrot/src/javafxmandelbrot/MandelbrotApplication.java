package javafxmandelbrot;

import javafx.application.Application;
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

/**
 *
 * @author Joris
 */
public class MandelbrotApplication extends Application implements EventHandler<ActionEvent> {

    final static int X_PIXEL = 300; // change this value if you have a slow (or fast...) laptop
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
    private Thread t;
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
        ThreadOverview threadOverview = new ThreadOverview();
        sim();
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

        // investigate the speed of coloring the canvas
        
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
        // TODO: stopping threads
        t.interrupt();
    }

    private void startThreads() {
        int nrofTiles;
        pixelManager = new PixelManager(gc, XY_SIZE);
        initCanvas();

        nrofTiles = Integer.parseInt(cboxGrid.getValue().toString());
        tileFactory.setNrofTiles(nrofTiles);

        for (int i = 0; i < nrofTiles; i++) {
            for (int j = 0; j < nrofTiles; j++) {
                Tile tile = tileFactory.createTile(i, j);
                Mandelbrot m = new Mandelbrot(tile, pixelManager);
                m.calculate();
                t = new Thread(m);
                t.start();
            }
        }
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
}
