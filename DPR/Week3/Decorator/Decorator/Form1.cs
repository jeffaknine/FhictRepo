using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Decorator
{
    public partial class Form1 : Form
    {
        ICar car;
        public Form1()
        {
            car = new Ford();
            InitializeComponent();
        }

        private void buttonBuy_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            if (checkBoxAC.Checked)
            {
                car = new AirConditionner(car);
            }
            if (checkBoxWheels.Checked)
            {
                car = new Wheel(car);
            }

            listBox1.Items.Add(car.description());
            listBox1.Items.Add("Cost = "+car.cost());
            car = new Ford();
        }
    }
}
