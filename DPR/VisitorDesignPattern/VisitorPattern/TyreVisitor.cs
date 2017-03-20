using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VisitorPattern
{
    class TyreVisitor : IVisitor
    {
        public string Info()
        {
            throw new NotImplementedException();
        }

        public void Visit(Element element)
        {
            Taxi taxi = element as Taxi;
            if (taxi.TyreType == "Summer")
            {
                taxi.TyreType = "Winter";
            }
            else taxi.TyreType = "Summer";
            Console.WriteLine("New tyres for this " + taxi.GetType().ToString() + " are " + taxi.TyreType);
        }
    }
}
