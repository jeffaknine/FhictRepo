using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Factory.Mercedes
{
    public class AClass : IFamilyCar
    {
        public int NumberOfSeats()
        {
            return 5;
        }

        public string type()
        {
            return "Hybrid";
        }
    }
}
