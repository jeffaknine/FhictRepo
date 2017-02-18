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
        Timer timer;
        int counter;
        List<string> classList;
        List<string> teacherList;
        public ClassroomManagerFrom()
        {
            InitializeComponent();
            classroomState = new ClassroomState();
            classroomManager = new ClassroomManager();

            classroomManager.Attach(new StudentAFrom(classroomManager));
            classroomManager.Attach(new StudentBFrom(classroomManager));

            classroomManager.classroomState = classroomState;

            classList = new List<string>();
            teacherList = new List<string>();

            teacherList.Add("Bob");
            teacherList.Add("Ben");
            teacherList.Add("Joe");
            teacherList.Add("Jack");
            teacherList.Add("John");

            classList.Add("ei1");
            classList.Add("ei2");
            classList.Add("ei3");
            classList.Add("ei4");
            classList.Add("ei5");

            timer = new Timer();
            timer.Tick += Timer_Tick;
            timer.Interval = (5000);
            timer.Start();
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            if (counter == 5)
            {
                counter = 0;
            }
            this.textBoxClass.Text = (classList[counter]).ToString();
            this.textBoxTeacher.Text = (teacherList[counter]).ToString();
            counter++;
        }

        private void textBoxClass_TextChanged(object sender, EventArgs e)
        {
            classroomState.Class = textBoxClass.Text;
            classroomManager.classroomState = classroomState;
        }

        private void textBoxTeacher_TextChanged(object sender, EventArgs e)
        {
            classroomState.TeacherName = textBoxTeacher.Text;
            classroomManager.classroomState = classroomState;
        }
    }
}
