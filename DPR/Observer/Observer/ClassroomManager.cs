using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Observer
{
    class ClassroomManager: IClassroomManager
    {
        List<IStudentObserver> studentObserverList;

        private ClassroomState _classroomState;

        public ClassroomState classroomState
        {
            get { return _classroomState; }
            set { _classroomState = value; this.Notify(); }
        }

        public ClassroomManager()
        {
            studentObserverList = new List<IStudentObserver>();            
        }

        public ClassroomState GetState()
        {
            return classroomState;
        }

        public void Attach(IStudentObserver student)
        {
            studentObserverList.Add(student);
        }

        public void Detach(IStudentObserver student)
        {
            studentObserverList.Remove(student);
        }

        public void Notify()
        {
            foreach (IStudentObserver s in studentObserverList)
            {
                s.Update();
            }
        }
    }
}
