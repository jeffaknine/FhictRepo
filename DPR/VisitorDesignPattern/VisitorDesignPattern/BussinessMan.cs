using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VisitorDesignPattern
{
    class BussinessMan : Visitor
    {
        public void Visit(Element element)
        {
            Taxi taxi = element as Taxi;

            Console.WriteLine("Bussiness man tiped: "+10+" euros");
        }
    }
}
