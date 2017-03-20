using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VisitorPattern
{
    class PremiumTaxi : Taxi
    {
        public PremiumTaxi() : base("200", 100)
        {
        }
    }
}
