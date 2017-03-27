using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IteratorDesignPatter
{
    class Program
    {
        static void Main(string[] args)
        {
            TunedChannel aggr = new TunedChannel();

            aggr[0] = "GolfChannel";
            aggr[1] = "NewsChannel";
            aggr[2] = "TennisChannel";
            aggr[3] = "BasketballChannel";
            aggr[4] = "FootballChannel";
            aggr[5] = "BaseballChannel";
            aggr[6] = "CrossfitChannel";
            aggr[7] = "CyclingChannel";
            aggr[8] = "RugbyChannel";
            aggr[9] = "AmericanFootballChannel";

            IChannelIterator iter = aggr.CreateIterator();
            Console.WriteLine(" This is a TV remote control"+
                                "\n Type the 'n' key followed by enter to get the next channel and 'p' for the previous one");

            while(true)
            {
                string key = Console.ReadLine();
                if (key == "n")
                {
                    Console.WriteLine(iter.Next);
                }
                if (key == "p")
                {
                    Console.WriteLine(iter.Previous);
                }                
            }
            
        }
    }
}
