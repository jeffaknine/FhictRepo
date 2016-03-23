package javafxmandelbrot;

import javafx.application.Platform;
import javafx.scene.canvas.GraphicsContext;
import sun.net.www.content.text.PlainTextInputStream;

/**
 *
 * @author Joris
 */
public class PixelManager implements Runnable{
    private int index =0;
    private final GraphicsContext gc;
    private Pixel[] pixelArray;

    PixelManager(GraphicsContext gc, int size) {
        this.gc = gc;
        pixelArray = new Pixel[size];
    }

    public synchronized void add(Pixel p) {

        int i;
        for (i = 0; i < pixelArray.length; i++)
        {
            if (pixelArray[i] == null)
            {
                index = i;
                break;
            }
        }
        pixelArray[index] = p;
    }

    
    public void show() {
        // TODO: display all pixels in pixelArray[], and empty the array afterwards

            // hint: 
            // one pixel, displayed as a 1x1 rectangle
            // gc.setFill(p.getColor());
            // gc.fillRect(p.getX(), p.getY(), 1, 1);
        Platform.runLater(this);

    }

    @Override
    public void run() {
        for (int i = 0; i < pixelArray.length; i++)
        {
            gc.setFill(pixelArray[i].getColor());
            gc.fillRect(pixelArray[i].getX(),pixelArray[i].getY(),1,1);
        }
    }
}
