using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Factory
{
    public class Dealership
    {
        IFamilyCar familyCar;
        ISportCar sportCar;
        ITruck truck;
        IFactory bmwFactory;
        IFactory mercedesFactory;

        public Dealership()
        {
            bmwFactory = new BMWFactory();
            mercedesFactory = new MercedesFactory();
        }

        public IFactory getBMWFactory()
        {
            return this.bmwFactory;
        }

        public IFactory getMercedesFactory()
        {
            return this.mercedesFactory;
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
