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
    }
}
