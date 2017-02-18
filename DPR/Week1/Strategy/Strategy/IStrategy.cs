using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Strategy
{
    /// <summary>
    /// Interface IStrategy which sorts the
    /// </summary>
    public interface IStrategy
    {
        int findNext(List<int> list, ref int head);
    }
}
