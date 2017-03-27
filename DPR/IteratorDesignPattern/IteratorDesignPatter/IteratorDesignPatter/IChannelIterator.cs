using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IteratorDesignPatter
{
    interface IChannelIterator
    {
        string Next { get; }
        string Previous { get; }
    }
}
