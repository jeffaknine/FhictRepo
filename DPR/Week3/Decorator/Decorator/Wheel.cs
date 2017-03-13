using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Decorator
{
    class Wheel : Accessory
    {
        ICar car;
        public Wheel(ICar car) : base(car)
        {
            this.car = car;
        }

        public override int cost()
        {
            return car.cost() + 200;
        }

        public override string description()
        {
            return car.description() + " has  wheels";
        }
    }
}
