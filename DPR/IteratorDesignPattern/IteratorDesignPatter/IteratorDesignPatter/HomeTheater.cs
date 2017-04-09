using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IteratorDesignPatter
{
    public class HomeTheater
    {
        string[] radio = new string[8];
        string[] tv = new string[10];
        
        IChannelFrequencies channels;
        IChannelIterator iterator;

        public HomeTheater()
        {
            channels = new RadioChannel();
            CreateTv();
            CreateRadio();
        }

        public string Get()
        {
            if(channels.GetType() == typeof(TunedChannel))
            {
                return "TV";
            }
            else
            {
                return "radio";
            }
        }

        public void Switch()
        {
            if (channels.GetType() == typeof(TunedChannel))
            {
                int count = 0;
                channels = new RadioChannel();
                foreach(String s in radio)
                {
                    channels[count] = radio[count];
                    count++;
                }
                iterator = new RadioChannelSelector(channels);
            }
            else
            {
                channels = new TunedChannel();
                int count = 0;
                foreach (String s in tv)
                {               
                    channels[count] = tv[count];
                    count++;                  
                }
                iterator = new ChannelSelector(channels);
            }
        }

        public string GetNext(string key)
        {
            if (key == "n")
            {
                return iterator.Next;
            }
            if (key == "p")
            {
                return iterator.Previous;
            }
            return "wrong button";
        }

        private void CreateTv()
        {
            tv[0] = "GolfChannel";
            tv[1] = "NewsChannel";
            tv[2] = "TennisChannel";
            tv[3] = "BasketballChannel";
            tv[4] = "FootballChannel";
            tv[5] = "BaseballChannel";
            tv[6] = "CrossfitChannel";
            tv[7] = "CyclingChannel";
            tv[8] = "RugbyChannel";
            tv[9] = "AmericanFootballChannel";
        }
        private void CreateRadio()
        {
            radio[0] = "81.5FM";
            radio[1] = "86.0FM";
            radio[2] = "87.12FM";
            radio[3] = "102.5FM";
            radio[4] = "106.5FM";
            radio[5] = "107.5FM";
            radio[6] = "101.5FM";
            radio[7] = "130.5FM";
        }
    }
}
