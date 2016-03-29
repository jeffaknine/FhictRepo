package javafxmandelbrot;

import javafx.application.Platform;
import javafx.scene.canvas.GraphicsContext;

import java.lang.reflect.Array;
import java.util.ArrayList;

/**
 *
 * @author Joris
 */
public class PixelManager implements Runnable {

    private final GraphicsContext gc;
    private Pixel pixelArray[];
    private int pai;

    PixelManager(GraphicsContext gc, int size) {
        this.gc = gc;
        pixelArray = new Pixel[size];
        pai = 0;
    }

    public synchronized void add(Pixel p) {

        // TODO: add p to pixelArray
        while (pai  >= pixelArray.length)
        {
            try{
                show();
                wait();
            }
            catch(InterruptedException ex){
                Thread.currentThread().interrupt();

            }
        }
        pixelArray[pai] = p;
        pai++;

    }


    public void show() {
        Platform.runLater(this);
    }

    @Override
    public synchronized void run() {

        for(int index = 0; index < pai; index++){
            Pixel p = pixelArray[index];
            if(p != null){

                gc.setFill(p.getColor());
                gc.fillRect(p.getX(), p.getY(), 1, 1);
                p = null;
            }
        }
        pai = 0;
        notify();
    }


}