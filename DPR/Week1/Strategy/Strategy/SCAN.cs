using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Strategy
{
    class SCAN : IStrategy
    {
        static bool i;
        static bool Checked = false;
        public int findNext(List<int> list,ref int head)
        {
            int half, position, remove = head;
            position = Math.Abs(list.Count - head);
            half = list.Count / 2;
            if(head == 0 || head==(list.Count-1))
            {
                Checked = false;
            }
            if (Checked == false)
            {
                i = (position > half && head != 0) || (head == (list.Count - 1));
                Checked = true;
            }            
            if (i)
            {
                head -= 1;
                return remove;
            }
            else
            {
                return remove;
            }
        }
    }
}
