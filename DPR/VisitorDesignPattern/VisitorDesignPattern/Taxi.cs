using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VisitorDesignPattern
{
    public class Taxi : Element
    {
        private string license;
        private int price;

        public Taxi(string license,int price)
        {
            this.license = license;
            this.price = price;
        }

        public string License
        {
            get { return license; }
            set { license = value; }
        }

        public int Price
        {
            get { return price; }
            set { price = value; }
        }
        public override void Accept(Visitor visitor)
        {
            visitor.Visit(this);
        }
    }
}
