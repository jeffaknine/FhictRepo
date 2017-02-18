using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

/// <summary>
/// random list of numbers, go to a value depending on the algorithm, delete the value, create a random one and add it in the list
/// the slider is the head
/// numbers are the cilinders that it needs to go to
/// 
/// </summary>
namespace Strategy
{
    public partial class Form1 : Form
    {
        DiskScheduler disk;
        public Form1()
        {
            InitializeComponent();
            trackBar1.Minimum = 0;
            trackBar1.Maximum = 100;
            disk = new DiskScheduler(listboxQueue, textBoxSelected, label1, trackBar1);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            disk.Stop();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            disk.Start();
        }

        private void FCFS_CheckedChanged(object sender, EventArgs e)
        {
            disk.Stop();
            if(FCFS.Checked)
            {
                disk.selectStrategy("FIFO");
            }
            disk.Start();
        }

        private void SSTF_CheckedChanged(object sender, EventArgs e)
        {
            disk.Stop();
            if (SSTF.Checked)
            {
                disk.selectStrategy("SSTF");
            }
            disk.Start();
        }

        private void SCAN_CheckedChanged(object sender, EventArgs e)
        {
            disk.Stop();
            if (SCAN.Checked)
            {
                disk.selectStrategy("SCAN");
            }
            disk.Start();
        }
    }
}
