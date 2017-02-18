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
    partial class StudentBFrom : Form, IStudentObserver
    {
        IClassroomManager classroomManager;

        public StudentBFrom(IClassroomManager c)
        {
            InitializeComponent();
            this.classroomManager = c;
            c.Attach(this);
            this.Show();
        }

        public new void Update()
        {
            ClassroomState cs = classroomManager.GetState();
            this.textBoxTeacher.Text = (cs.TeacherName);
        }
    }
}
