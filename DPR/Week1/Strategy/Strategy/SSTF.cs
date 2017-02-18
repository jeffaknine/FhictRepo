using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Strategy
{
    class SSTF : IStrategy
    {
        public int findNext(List<int> list, ref int head)
        {
            int up, low;
            int remove = head;
            if (head != 0)
            {
                if (head != (list.Count-1))
                {
                    up = Math.Abs(list[head] - list[head + 1]);
                }
                else up = 0;
                low = Math.Abs(list[head] - list[head - 1]);
                if (up < low)
                {
                    return remove;
                }
                else
                {
                    head = head - 1;
                    return remove;
                }
            }
            return remove;
        }
    }
}
