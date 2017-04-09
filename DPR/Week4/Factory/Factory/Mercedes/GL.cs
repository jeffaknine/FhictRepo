using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Factory.Mercedes
{
    class GL : ITruck
    {
        public bool FourbyFour()
        {
            return true;
        }

        public int MaxWeight()
        {
            return 1000;
        }
        public override string ToString()
        {
            if (FourbyFour())
            {
                return "Mercedes GL that handles " + MaxWeight() + " kilograms and is a 4x4";
            }
            else
            {
                return "Mercedes GL that handles " + MaxWeight() + " kilograms and isn't a 4x4";
            }
        }
    }
}
