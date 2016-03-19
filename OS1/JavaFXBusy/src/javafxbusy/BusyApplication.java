/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javafxbusy;

import javafx.event.ActionEvent;
import java.util.Calendar;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

/**
 *
 * @author Joris
 */
public class BusyApplication extends Application {


    class ButtonHandler implements EventHandler<ActionEvent>{

        @Override
        public void handle(ActionEvent event) {
            label1.setText(Calendar.getInstance().getTime().toString()
                    + "; milliseconds: "
                    + Calendar.getInstance().get(Calendar.MILLISECOND));

        }
    }

    /**
     * The main() method is ignored in correctly deployed JavaFX application.
     * main() serves only as fallback in case the application can not be
     * launched through deployment artifacts, e.g., in IDEs with limited FX
     * support. NetBeans ignores main().
     *
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }

    private Button btn1, btn2, btn3, btn4;
    private Label label1;
    private static Label label2;
    private VBox v;
    private ButtonHandler bh =new ButtonHandler();
    private BusyWorker bw, bw1;
    public UpdateLabel ul;
    private Thread t;

    @Override
    public void start(Stage primaryStage) {
        label1 = new Label("");
        label2 = new Label("");

        btn1 = new Button();
        v = new VBox();
        btn2=new Button();
        bw=new BusyWorker(5000);

        btn3 = new Button();
        btn4 = new Button();

        btn1.setOnAction(bh);
        btn2.setOnAction(new EventHandler<ActionEvent>(){
           @Override
            public void handle (ActionEvent e){
             bw.busyJob();    
            }
        });
        btn3.setOnAction(new EventHandler<ActionEvent>(){

            @Override
            public void handle (ActionEvent e){
                Runnable r = new BusyWorker(5000);
                t = new Thread(r);
                t.start();;
            }
        });
        btn4.setOnAction(new EventHandler<ActionEvent>(){

            @Override
            public void handle (ActionEvent e){
                t.interrupt();
            }
        });


        v.getChildren().add(btn1);
        v.getChildren().add(label1);
        v.getChildren().add(btn3);
        v.getChildren().add(btn4);
        v.getChildren().add(label2);
        v.setPadding(new Insets(50,50,50,50));
        v.setSpacing(20);

        //scene object with the vbox as root and sizes
        Scene s = new Scene(v,500,300);


        btn1.setText("show current time");
        btn2.setText("worker");
        btn3.setText("Busy Worker");
        btn4.setText("stop");
        // TODO: VBox, Scene, Stage actions

        label1.setText(Calendar.getInstance().getTime().toString()
                + "; milliseconds: "
                + Calendar.getInstance().get(Calendar.MILLISECOND));

        primaryStage.setTitle("Week3");
        primaryStage.setScene(s);
        primaryStage.show();

    }

    static class UpdateLabel implements Runnable{

        @Override
        public void run() {
            label2.setText(Calendar.getInstance().getTime().toString()
                    + "; milliseconds: "
                    + Calendar.getInstance().get(Calendar.MILLISECOND));
        }


}


}
   