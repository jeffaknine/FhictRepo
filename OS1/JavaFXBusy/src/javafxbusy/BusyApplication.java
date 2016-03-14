    /*
     * To change this license header, choose License Headers in Project Properties.
     * To change this template file, choose Tools | Templates
     * and open the template in the editor.
     */
    package javafxbusy;
    import java.util.Calendar;
    import javafx.application.Application;
    import javafx.event.ActionEvent;
    import javafx.event.EventHandler;
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

        public static void main(String[] args) {
            launch(args);

        }
        private boolean moreTime = true;
        private Button btn1, btn2, btn3,btn4;
        private Label label1, label2;
        private VBox vBox;
        private Scene scene;

        public class UpdateLabel implements Runnable {


            private Label theLabel;

            public UpdateLabel(Label label) {
               theLabel =label;
            }

            @Override
            public void run() {
                        theLabel.setText(Calendar.getInstance().getTime().toString()
                                + "; milliseconds: "
                                + Calendar.getInstance().get(Calendar.MILLISECOND));
            }

        }


        @Override

        public void start(Stage primaryStage) {
            label1 = new Label();
            label2 = new Label();
            btn1 = new Button();
            btn2 = new Button();
            btn3 = new Button();
            btn4 = new Button();
            vBox = new VBox(8);

            UpdateLabel myUpdatedLabel = new UpdateLabel(label2);
            BusyWorker myBusyWorker2 = new BusyWorker(myUpdatedLabel, 5000);
            Thread t = new Thread(myBusyWorker2);
            t.start();


            BusyWorker myBusyWorker = new BusyWorker(5000);

            btn1.setText("show current time");
            btn2.setText("Work");
            btn3.setText("Work but do stuff in the meantime");
            btn4.setText("Stop the time");
            btn1.setOnAction(new EventHandler<ActionEvent>() {
                @Override
                public void handle(ActionEvent event) {
                    label1.setText(Calendar.getInstance().getTime().toString()
                            + "; milliseconds: "
                            + Calendar.getInstance().get(Calendar.MILLISECOND));
                }

            });

            btn2.setOnAction(new EventHandler<ActionEvent>() {
                @Override
                public void handle(ActionEvent event) {
                    myBusyWorker.busyJob();
                }

            });
            btn3.setOnAction(new EventHandler<ActionEvent>() {
                @Override
                public void handle(ActionEvent event) {
                    BusyWorker r = new BusyWorker();
                    Thread t = new Thread(r);
                    t.start();
                }

            });
            btn4.setOnAction(new EventHandler<ActionEvent>() {
                @Override
                public void handle(ActionEvent event) {
                    moreTime = !moreTime;
                }

            });

            // TODO: VBox, Scene, Stage actions
            vBox.getChildren().addAll(btn1, label1, btn2, btn3, label2,btn4);

            vBox.setSpacing(30);
            scene = new Scene(vBox, 300, 300);
            primaryStage.setTitle("Busy app");
            primaryStage.setScene(scene);
            primaryStage.show();

        }

    }
