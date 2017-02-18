using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Observer
{
    public class ClassroomState
    {
        public string TeacherName { get; set; }
        public string Class { get; set; }

        public ClassroomState()
        {
            TeacherName = "Bob";
            Class = "Ei1";
        }
    }
}
