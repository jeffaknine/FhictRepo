using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Factory
{
    public partial class Form1 : Form
    {
    
        Dealership dealership;

        public Form1()
        {
            InitializeComponent();
            listBoxType.Items.Add("Family car");
            listBoxType.Items.Add("Sport car");
            listBoxType.Items.Add("Truck");
            dealership = new Dealership();

        }

        private void listBoxType_SelectedIndexChanged(object sender, EventArgs e)
        {
            listBoxBrand.Items.Clear();
            listBoxBrand.Items.Add("BMW");
            listBoxBrand.Items.Add("Mercedes");
        }

        private void listBoxBrand_SelectedIndexChanged(object sender, EventArgs e)
        {
            listBoxInfo.Items.Clear();
            if (listBoxType.SelectedIndex == 0)
            {
                if (listBoxBrand.SelectedIndex==0)
                {
                    dealership.CreateFamilyCar(dealership.getBMWFactory().createFamilyCar());
                    listBoxInfo.Items.Add(dealership.getFamilyCar().ToString());
                }
                if (listBoxBrand.SelectedIndex == 1)
                {
                    dealership.CreateFamilyCar(dealership.getMercedesFactory().createFamilyCar());
                    listBoxInfo.Items.Add(dealership.getFamilyCar().ToString());
                }
            }
            if (listBoxType.SelectedIndex == 1)
            {
                if (listBoxBrand.SelectedIndex == 0)
                {
                    dealership.CreateSportCar(dealership.getBMWFactory().createSportCar());
                    listBoxInfo.Items.Add(dealership.getSportCar().ToString());
                }
                if (listBoxBrand.SelectedIndex == 1)
                {
                    dealership.CreateSportCar(dealership.getMercedesFactory().createSportCar());
                    listBoxInfo.Items.Add(dealership.getSportCar().ToString());
                }
            }
            if (listBoxType.SelectedIndex == 2)
            {
                if (listBoxBrand.SelectedIndex == 0)
                {
                    dealership.CreateTruck(dealership.getBMWFactory().createTruck());
                    listBoxInfo.Items.Add(dealership.getTruck().ToString());
                }
                if (listBoxBrand.SelectedIndex == 1)
                {
                    dealership.CreateTruck(dealership.getMercedesFactory().createTruck());
                    listBoxInfo.Items.Add(dealership.getTruck().ToString());
                }
            }
        }
    }
}
