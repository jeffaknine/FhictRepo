using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VisitorPattern
{
    public class Taxi : Element
    {
        private string license;
        private string tyreType;
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

        public string TyreType
        {
            get { return tyreType; }
            set { tyreType = value; }
        }
        public override void Accept(IVisitor visitor)
        {
            visitor.Visit(this);
        }
    }
}
