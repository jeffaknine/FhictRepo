namespace Observer
{
    partial class ClassroomManagerFrom
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.textBoxClass = new System.Windows.Forms.TextBox();
            this.textBoxTeacher = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(61, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(67, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "current class";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(307, 16);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(84, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Current Teacher";
            // 
            // textBoxClass
            // 
            this.textBoxClass.Location = new System.Drawing.Point(33, 25);
            this.textBoxClass.Name = "textBoxClass";
            this.textBoxClass.Size = new System.Drawing.Size(100, 20);
            this.textBoxClass.TabIndex = 3;
            this.textBoxClass.TextChanged += new System.EventHandler(this.textBoxClass_TextChanged);
            // 
            // textBoxTeacher
            // 
            this.textBoxTeacher.Location = new System.Drawing.Point(300, 32);
            this.textBoxTeacher.Name = "textBoxTeacher";
            this.textBoxTeacher.Size = new System.Drawing.Size(100, 20);
            this.textBoxTeacher.TabIndex = 4;
            this.textBoxTeacher.TextChanged += new System.EventHandler(this.textBoxTeacher_TextChanged);
            // 
            // ClassroomManagerFrom
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(460, 197);
            this.Controls.Add(this.textBoxTeacher);
            this.Controls.Add(this.textBoxClass);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "ClassroomManagerFrom";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBoxClass;
        private System.Windows.Forms.TextBox textBoxTeacher;
    }
}

