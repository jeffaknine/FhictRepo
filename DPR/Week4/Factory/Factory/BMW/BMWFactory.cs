using Factory.BMW;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Factory
{
    public class BMWFactory : IFactory
    {
        public IFamilyCar createFamilyCar()
        {
            return new Series5();
        }

        public ISportCar createSportCar()
        {
            return new Z4();
        }

        public ITruck createTruck()
        {
            return new X5();
        }
    }
}
