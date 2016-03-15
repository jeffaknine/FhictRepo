package javafxmandelbrot;

import javafx.scene.canvas.GraphicsContext;

/**
 *
 * @author Joris
 */
public class PixelManager {

    private final GraphicsContext gc;
    private Pixel[] pixelArray;

    PixelManager(GraphicsContext gc, int size) {
        this.gc = gc;
        pixelArray = new Pixel[size];
    }

    public void add(Pixel p) {
        
        // TODO: add p to pixelArray
    }

    
    public void show() {
        // TODO: display all pixels in pixelArray[], and empty the array afterwards

            // hint: 
            // one pixel, displayed as a 1x1 rectangle
            // gc.setFill(p.getColor());
            // gc.fillRect(p.getX(), p.getY(), 1, 1);
    }
}
