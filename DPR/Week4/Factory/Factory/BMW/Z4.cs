using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Factory.BMW
{
    public class Z4 : ISportCar
    {
        public int HorsePower()
        {
            return 400;
        }

        public string WheelDrive()
        {
            return "rear";
        }
    }
}
