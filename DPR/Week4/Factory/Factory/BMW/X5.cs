using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Factory.BMW
{
    public class X5 : ITruck
    {
        public bool FourbyFour()
        {
            return false;
        }

        public int MaxWeight()
        {
            return 500;
        }

        public override string ToString()
        {
            if (FourbyFour())
            {
                return "BMW X5 that handles " + MaxWeight() + " kilograms and is a 4x4";
            }
            else
            {
                return "BMW X5 that handles " + MaxWeight() + " kilograms and isn't a 4x4";
            }
            
        }
    }
}
