using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VisitorPattern
{
    class PriceVisitor : IVisitor
    {
        string temp;
        public string Info()
        {
            return temp;
        }

        public void Visit(Element element)
        {
            Taxi taxi = element as Taxi;
            taxi.Price += 50;
            Console.WriteLine("New Price for this " + taxi.GetType().ToString()+" is "+taxi.Price);
        }
    }
}
