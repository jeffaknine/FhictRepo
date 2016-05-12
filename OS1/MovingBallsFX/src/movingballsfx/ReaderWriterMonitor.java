package movingballsfx;

/**
 * Created by jeff on 9-5-16.
 */
public class ReaderWriterMonitor {
    private int readersActive = 0;
    private int writersActive = 0;
    private int writersWaiting = 0;
    private int readerWaiting = 0;

    public void enterReader()
            throws InterruptedException
    {
        while (writersActive != 0)
        {
            writersWaiting++;
            wait();
            writersWaiting--;
        }
        readersActive ++;

    }

    public synchronized void exitReader()
    {
        readersActive--;
        notifyAll();
    }

    public synchronized void enterWriter()
            throws InterruptedException
    {
        while ((writersActive != 0) || (writersWaiting > 0))
        {
            readerWaiting++;
            wait();
            readerWaiting--;
        }
        writersActive ++;
    }
    public synchronized void exitWriter()
    {
        writersActive--;
        notifyAll();
    }

}
