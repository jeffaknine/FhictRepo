using Microsoft.VisualStudio.TestTools.UnitTesting;
using Factory;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Factory.Tests
{
    [TestClass()]
    public class DealershipTests
    {       

        [TestMethod()]
        public void CreateBMWFamilyCarTest()
        {
            var target = new Dealership();
            target.CreateFamilyCar(target.getBMWFactory().createFamilyCar());
            Assert.IsInstanceOfType(target.getFamilyCar(), new BMWFactory().createFamilyCar().GetType());
        }

        [TestMethod()]
        public void CreateMercedesFamilyCarTest()
        {
            var target = new Dealership();
            target.CreateFamilyCar(target.getMercedesFactory().createFamilyCar());
            Assert.IsInstanceOfType(target.getFamilyCar(), new MercedesFactory().createFamilyCar().GetType());
        }


        [TestMethod()]
        public void CreateBMWTruckTest()
        {
            var target = new Dealership();
            target.CreateTruck(target.getBMWFactory().createTruck());
            Assert.IsInstanceOfType(target.getTruck(), new BMWFactory().createTruck().GetType());
        }

        [TestMethod()]
        public void CreateMercedesTruckTest()
        {
            var target = new Dealership();
            target.CreateTruck(target.getMercedesFactory().createTruck());
            Assert.IsInstanceOfType(target.getTruck(), new MercedesFactory().createTruck().GetType());
        }

        [TestMethod()]
        public void CreateBMWSportCarTest()
        {
            var target = new Dealership();
            target.CreateSportCar(target.getBMWFactory().createSportCar());
            Assert.IsInstanceOfType(target.getSportCar(), new BMWFactory().createSportCar().GetType());
        }

        [TestMethod()]
        public void CreateMercedesSportCarTest()
        {
            var target = new Dealership();
            target.CreateSportCar(target.getMercedesFactory().createSportCar());
            Assert.IsInstanceOfType(target.getSportCar(), new MercedesFactory().createSportCar().GetType());
        }
    }
}