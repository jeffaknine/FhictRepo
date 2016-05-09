/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package movingballsfx;

/**
 *
 * @author Peter Boots
 */
public class BallRunnable implements Runnable {

    private final Ball ball;

    public BallRunnable(Ball ball) {
        this.ball = ball;
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
            busySleep(ball.getSpeed());
        }
    }
}
