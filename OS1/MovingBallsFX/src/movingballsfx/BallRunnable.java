/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package movingballsfx;

import javafx.scene.paint.Color;
import javafx.scene.paint.Paint;

/**
 *
 * @author Peter Boots
 */
public class BallRunnable implements Runnable {

    private final Ball ball;
    private ReaderWriterMonitor monitor;

    public BallRunnable(Ball ball,ReaderWriterMonitor monitor)
    {
        this.ball = ball;this.monitor = monitor;
    }

    private void busySleep(long ms)
    {
        long end = System.currentTimeMillis() + ms;
        
        while (System.currentTimeMillis() < end)
        {
            // busy waiting...
        }
    }

    @Override
    public void run() {
        while (!Thread.currentThread().isInterrupted()) {
            ball.move();
            isInGreen(ball);
            busySleep(ball.getSpeed());
        }
    }

    private void isInGreen(Ball ball)
    {
        if (ball.isEnteringCs())
        {
            if (ball.getColor() == Color.RED)
            {
                try
                {
                    monitor.enterReader();
                }
                catch (InterruptedException ex)
                {
                    System.out.print(ex.toString());
                }
            }
            else if (ball.getColor() == Color.BLUE)
            {
                try
                {
                    monitor.enterWriter();
                }
                catch (InterruptedException ex)
                {
                    System.out.print(ex.toString());
                }
            }
        }
        if (ball.isLeavingCs())
        {

            if (ball.getColor() == Color.RED)
            {
                monitor.exitReader();
            }
            else if(ball.getColor() == Color.BLUE)
            {
                monitor.exitWriter();
            }
        }
    }


}
