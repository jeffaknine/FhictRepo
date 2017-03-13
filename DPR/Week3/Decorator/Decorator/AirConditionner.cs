using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Decorator
{
    public class AirConditionner : Accessory
    {
        ICar car;
        public AirConditionner(ICar car) : base(car)
        {
            this.car = car;
        }

        public override int cost()
        {
            return car.cost() + 150;
        }

        public override string description()
        {
            return car.description() + " has air conditionning";
        }
    }
}
