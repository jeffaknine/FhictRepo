using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Factory.Mercedes
{
    class SLS : ISportCar
    {
        public int HorsePower()
        {
            return 550;
        }

        public string WheelDrive()
        {
            return "Rear";
        }

        public override string ToString()
        {
            return "Mercedes SLS has " + HorsePower() + " horse power and is " + WheelDrive() + " wheel drive";
        }
    }
}
