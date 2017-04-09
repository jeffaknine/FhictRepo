using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IteratorDesignPatter
{
    public class RadioChannelSelector : IChannelIterator
    {
        IChannelFrequencies aggregate = null;
        int currentId = 0;

        public RadioChannelSelector(IChannelFrequencies aggregate)
        {
            this.aggregate = aggregate;
        }


        public string Next
        {
            get
            {
                currentId += 1;
                if (currentId < aggregate.Count)
                {
                    return aggregate[currentId];
                }
                else
                {
                    currentId = 0;
                    return aggregate[currentId];
                }
            }
        }

        public string Previous
        {
            get
            {
                try
                {
                    currentId -= 1;
                    return aggregate[currentId];
                }
                catch (Exception)
                {
                    currentId = aggregate.Count - 1;
                    return aggregate[currentId];
                }

            }
        }
    }
}
