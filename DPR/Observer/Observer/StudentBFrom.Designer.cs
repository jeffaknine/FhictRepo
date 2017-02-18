namespace Observer
{
    partial class StudentBFrom
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
            this.Teachers = new System.Windows.Forms.Label();
            this.listBoxUpdatesB = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // Teachers
            // 
            this.Teachers.AutoSize = true;
            this.Teachers.Location = new System.Drawing.Point(34, 14);
            this.Teachers.Name = "Teachers";
            this.Teachers.Size = new System.Drawing.Size(52, 13);
            this.Teachers.TabIndex = 5;
            this.Teachers.Text = "Teachers";
            // 
            // listBoxUpdatesB
            // 
            this.listBoxUpdatesB.FormattingEnabled = true;
            this.listBoxUpdatesB.Location = new System.Drawing.Point(34, 32);
            this.listBoxUpdatesB.Name = "listBoxUpdatesB";
            this.listBoxUpdatesB.Size = new System.Drawing.Size(120, 95);
            this.listBoxUpdatesB.TabIndex = 4;
            // 
            // StudentBFrom
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(187, 152);
            this.Controls.Add(this.Teachers);
            this.Controls.Add(this.listBoxUpdatesB);
            this.Name = "StudentBFrom";
            this.Text = "StudentB";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label Teachers;
        private System.Windows.Forms.ListBox listBoxUpdatesB;
    }
}