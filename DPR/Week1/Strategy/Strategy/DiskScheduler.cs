using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Strategy
{
   internal class DiskScheduler
    {
        private List<int> array;
        private System.Windows.Forms.Timer timer;
        private ListBox list;
        private string current = "";
        private TextBox box;
        private Dictionary<string, IStrategy> strategies;
        private int head; // head current
        private int temp; // index to remove
        private Random random;
        private Label label;
        private TrackBar trackbar;
        public DiskScheduler(ListBox list1,TextBox box1,Label label1,TrackBar bar)
        {
            random = new Random();
            list = list1;
            box = box1;
            trackbar = bar;
            label = label1;
            timer = new System.Windows.Forms.Timer();
            timer.Tick += Timer_Tick;
            timer.Interval = 8000;
            timer.Enabled = true;
            timer.Stop();
            array = new List<int>();
            strategies = new Dictionary<string, IStrategy>();
            strategies.Add("FIFO", new FIFO());
            strategies.Add("SSTF", new SSTF());
            strategies.Add("SCAN", new SCAN());
            for (int i = 0; i < 10; i++)
            {
                
                addNode();
              
            }
            head = 9;
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            if (current != "")
            {
                label.Text = array[head].ToString();
                temp = strategies[current].findNext(array, ref head);
                box.Text = array[temp].ToString();
                trackbar.Value = array[head];
                removeNode(temp);
                addNode();
                
                box.Text = array[temp].ToString();
                trackbar.Value = array[head];
                label.Text = array[head].ToString();
            }

        }

        public void removeNode(int toRemove)
        {
            array.RemoveAt(toRemove);
            list.Items.RemoveAt(toRemove);
        }

        public void addNode()
        {
            int i = Math.Abs(random.Next(100));
            array.Add(i);
            list.Items.Add(i);
        }

        public void selectStrategy(string strategy)
        {
            current = strategy;
        }

        public void Start()
        {
            timer.Start();
        }

        public void Stop()
        {
            timer.Stop();
        }

    }
}
