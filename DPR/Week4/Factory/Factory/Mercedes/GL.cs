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
    }
}
