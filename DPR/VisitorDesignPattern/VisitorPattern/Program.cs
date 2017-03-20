using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VisitorPattern
{
    class Program
    {
        static void Main(string[] args)
        {
            TaxiPark taxiPark = new TaxiPark();
            taxiPark.Attach(new BasicTaxi());
            taxiPark.Attach(new PremiumTaxi());
            taxiPark.Attach(new LimoTaxi());
            taxiPark.Accept(new PriceVisitor());
            taxiPark.Accept(new TyreVisitor());
            taxiPark.Accept(new TyreVisitor());
            Console.ReadKey();
        }
    }
}
