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
        IFactory bmwFactory;
        IFactory mercedesFactory;
        Dealership dealership;

        public Form1()
        {
            InitializeComponent();
            bmwFactory = new BMWFactory();
            mercedesFactory = new MercedesFactory();
            listBoxType.Items.Add("Family car");
            listBoxType.Items.Add("Sport car");
            listBoxType.Items.Add("Truck");

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
                    dealership = new Dealership(bmwFactory);
                    dealership.CreateFamilyCar(dealership.getFactory().createFamilyCar());
                    listBoxInfo.Items.Add(dealership.getFamilyCar().NumberOfSeats().ToString());
                    listBoxInfo.Items.Add(dealership.getFamilyCar().type().ToString());
                }
                if (listBoxBrand.SelectedIndex == 1)
                {
                    dealership = new Dealership(mercedesFactory);
                    dealership.CreateFamilyCar(dealership.getFactory().createFamilyCar());
                    listBoxInfo.Items.Add(dealership.getFamilyCar().NumberOfSeats().ToString());
                    listBoxInfo.Items.Add(dealership.getFamilyCar().type().ToString());
                }
            }
            if (listBoxType.SelectedIndex == 1)
            {
                if (listBoxBrand.SelectedIndex == 0)
                {
                    dealership = new Dealership(bmwFactory);
                    dealership.CreateSportCar(dealership.getFactory().createSportCar());
                    listBoxInfo.Items.Add(dealership.getSportCar().WheelDrive().ToString());
                    listBoxInfo.Items.Add(dealership.getSportCar().HorsePower().ToString());
                }
                if (listBoxBrand.SelectedIndex == 1)
                {
                    dealership = new Dealership(mercedesFactory);
                    dealership.CreateSportCar(dealership.getFactory().createSportCar());
                    listBoxInfo.Items.Add(dealership.getSportCar().WheelDrive().ToString());
                    listBoxInfo.Items.Add(dealership.getSportCar().HorsePower().ToString());
                }
            }
            if (listBoxType.SelectedIndex == 2)
            {
                if (listBoxBrand.SelectedIndex == 0)
                {
                    dealership = new Dealership(bmwFactory);
                    dealership.CreateTruck(dealership.getFactory().createTruck());
                    listBoxInfo.Items.Add(dealership.getTruck().FourbyFour().ToString());
                    listBoxInfo.Items.Add(dealership.getTruck().MaxWeight().ToString());
                }
                if (listBoxBrand.SelectedIndex == 1)
                {
                    dealership = new Dealership(mercedesFactory);
                    dealership.CreateTruck(dealership.getFactory().createTruck());
                    listBoxInfo.Items.Add(dealership.getTruck().FourbyFour().ToString());
                    listBoxInfo.Items.Add(dealership.getTruck().MaxWeight().ToString());
                }
            }
        }
    }
}
