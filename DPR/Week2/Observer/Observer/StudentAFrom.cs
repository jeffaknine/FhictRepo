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
    partial class StudentAFrom : Form , IStudentObserver
    {
        IClassroomManager classroomManager;

        public StudentAFrom(IClassroomManager c)
        {
            InitializeComponent();
            this.classroomManager = c;
            c.Attach(this);
        }
        
        public void Update()
        {
            ClassroomState cs = classroomManager.GetState();
            this.listBoxUpdatesA.Items.Add(cs.Class);
        }
    }
}
