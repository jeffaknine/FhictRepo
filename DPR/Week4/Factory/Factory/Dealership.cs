using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Factory
{
    public class Dealership
    {
        IFactory factory;
        IFamilyCar familyCar;
        ISportCar sportCar;
        ITruck truck;

        public Dealership(IFactory factory)
        {
            this.factory = factory;
        }
        
        public IFactory getFactory()
        {
            return this.factory;
        }

        public IFamilyCar getFamilyCar()
        {
            return familyCar;
        }

        public void CreateFamilyCar(IFamilyCar car)
        {
            familyCar = car;
        }

        public ITruck getTruck()
        {
            return truck;
        }

        public void CreateTruck(ITruck truck)
        {
            this.truck = truck;
        }

        public ISportCar getSportCar()
        {
            return this.sportCar;
        }

        public void CreateSportCar(ISportCar car)
        {
            sportCar = car;
        }
    }
}
