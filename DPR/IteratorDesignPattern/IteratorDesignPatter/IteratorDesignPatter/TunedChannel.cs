using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IteratorDesignPatter
{
    class TunedChannel : IChannelFrequencies
    {

        List<string> values = null;

        public TunedChannel()
        {
            values = new List<string>();
        }

        public string this[int itemIndex]
        {
            get
            {
                if (itemIndex < values.Count)
                {
                    return values[itemIndex];
                }
                else
                {
                    return string.Empty;
                }
            }
            set
            {
                values.Add(value);
            }
        }

        public int Count
        {
            get
            {
                return values.Count;
            }
        }

        public IChannelIterator CreateIterator()
        {
            return new ChannelSelector(this);
        }
    }
}
