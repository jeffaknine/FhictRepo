using Factory.Mercedes;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Factory
{
    public class MercedesFactory : IFactory
    {
        public IFamilyCar createFamilyCar()
        {
            return new AClass();
        }

        public ISportCar createSportCar()
        {
            return new SLS();
        }

        public ITruck createTruck()
        {
            return new GL();
        }
    }
}
