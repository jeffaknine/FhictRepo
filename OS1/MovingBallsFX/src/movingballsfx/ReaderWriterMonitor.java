package movingballsfx;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * Created by jeff on 9-5-16.
 */
public class ReaderWriterMonitor {
    private int readersActive = 0;
    private int writersActive = 0;
    private int writersWaiting = 0;
    private int readerWaiting = 0;
    public boolean checkPriority = false;
    Lock monLock = new ReentrantLock();
    Condition blue = monLock.newCondition();
    Condition red = monLock.newCondition();

    public void enterReader()
    {
        monLock.lock();
        try {

            while ((writersActive != 0) || (writersWaiting > 0 && checkPriority == false)) {
                readerWaiting++;
                blue.wait();
                readerWaiting--;

            }
            readersActive++;
        }
        catch (InterruptedException ex)
        {
            System.out.println(ex.toString());
        }
        finally {
            monLock.unlock();
        }
    }


//    public synchronized void enterReader()
//            throws InterruptedException
//    {
//        while ((writersActive != 0) || (writersWaiting > 0 && checkPriority == false))
//        {
//            readerWaiting++;
//            wait();
//            readerWaiting--;
//
//        }
//        readersActive ++;
//
//    }

    public synchronized void exitReader()
    {
        readersActive--;
        notifyAll();
    }

    public synchronized void enterWriter()
            throws InterruptedException
    {
        while ((writersActive != 0) || (readersActive !=0))
        {
            writersWaiting++;
            wait();
            writersWaiting--;
        }
        writersActive ++;
    }
    public synchronized void exitWriter()
    {
        writersActive--;
        notifyAll();
    }

}
