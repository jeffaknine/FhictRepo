package javafxmandelbrot;

import javafx.application.Platform;
import javafx.scene.canvas.GraphicsContext;

/**
 *
 * @author Joris
 */
public class PixelManager implements Runnable {

    final Buffer buffer = new BufferOK();

    private final GraphicsContext gc;
    private Pixel[] pixelArray;

    PixelManager(GraphicsContext gc, int size) {
        this.gc = gc;
        pixelArray = new Pixel[size];
    }

    public synchronized void add(Pixel p) {

        // TODO: add p to pixelArray

        for(int index = 0; index < pixelArray.length; index++){
            if(pixelArray[index] == null){
                pixelArray[index] = p;
                break;
            }
        }

    }


    public void show() {
        Platform.runLater(this);
    }

    @Override
    public void run() {

        for(int index = 0; index < pixelArray.length; index++){

            if(pixelArray[index] != null){

                gc.setFill(pixelArray[index].getColor());
                gc.fillRect(pixelArray[index].getX(), pixelArray[index].getY(), 1, 1);
                pixelArray[index] = null;
            }
        }
    }


}