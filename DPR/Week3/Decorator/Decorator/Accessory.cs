using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Decorator
{
    public abstract class Accessory : ICar
    {
        ICar car;

        public Accessory(ICar car)
        {
            this.car = car;
        }

        public virtual int cost()
        {
            return car.cost();
        }

        public virtual string description()
        {
            return car.description();
        }
    }
}
