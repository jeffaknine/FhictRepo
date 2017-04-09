using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IteratorDesignPatter
{
    public interface IChannelFrequencies
    {
        int Count { get;}
        string this[int itemIndex] { get; set; }
        IChannelIterator CreateIterator();
    }
}
