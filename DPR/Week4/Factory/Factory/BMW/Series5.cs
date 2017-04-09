using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Factory.BMW
{
    public class Series5 : IFamilyCar
    {
        public int NumberOfSeats()
        {
            return 5;
        }

        public string type()
        {
            return "Diesel";
        }

        public override String ToString()
        {
            return "BMW Series 5 with " + NumberOfSeats().ToString() + " seats \n and running on " + type();
        }
    }
}
