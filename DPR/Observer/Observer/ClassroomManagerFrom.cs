using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Observer
{
    public partial class ClassroomManagerFrom : Form
    {
        ClassroomManager classroomManager;
        ClassroomState classroomState;
        Timer time;
        Random random;

        public ClassroomManagerFrom()
        {
            InitializeComponent();
            classroomState = new ClassroomState();
            classroomManager = new ClassroomManager();

            classroomManager.Attach(new StudentAFrom(classroomManager));
            classroomManager.Attach(new StudentBFrom(classroomManager));

            classroomManager.classroomState = classroomState;

        }
    }
}
