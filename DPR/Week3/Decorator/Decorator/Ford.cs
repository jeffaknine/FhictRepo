using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Decorator
{
    public class Ford : ICar
    {
        public int cost()
        {
            return 10000;
        }
        public string description()
        {
            return "Ford ";
        }
    }
}
