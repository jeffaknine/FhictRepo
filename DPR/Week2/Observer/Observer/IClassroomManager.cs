using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Observer
{
    interface IClassroomManager
    {
        void Attach(IStudentObserver student);
        void Detach(IStudentObserver student);
        ClassroomState GetState();
    }
}
