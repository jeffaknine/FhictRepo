using Microsoft.VisualStudio.TestTools.UnitTesting;
using IteratorDesignPatter;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IteratorDesignPatter.Tests
{
    [TestClass()]
    public class HomeTheaterTests
    {

        [TestMethod()]
        public void GetRadioTest()
        {
            HomeTheater home = new HomeTheater();
            Assert.AreEqual("radio", home.Get());
        }

        [TestMethod()]
        public void GetTVTest()
        {
            HomeTheater home = new HomeTheater();
            home.Switch();
            Assert.AreEqual("TV", home.Get());
        }

        [TestMethod()]
        public void GetNextTest()
        {
            HomeTheater home = new HomeTheater();
            home.Switch();
            Assert.IsInstanceOfType(home.GetNext("n"),typeof(string));
        }
    }
}