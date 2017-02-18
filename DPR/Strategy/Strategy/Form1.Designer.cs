namespace Strategy
{
    partial class Form1
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
            this.trackBar1 = new System.Windows.Forms.TrackBar();
            this.panel1 = new System.Windows.Forms.Panel();
            this.FCFS = new System.Windows.Forms.RadioButton();
            this.SSTF = new System.Windows.Forms.RadioButton();
            this.SCAN = new System.Windows.Forms.RadioButton();
            this.listboxQueue = new System.Windows.Forms.ListBox();
            this.textBoxSelected = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).BeginInit();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // trackBar1
            // 
            this.trackBar1.Location = new System.Drawing.Point(12, 12);
            this.trackBar1.Name = "trackBar1";
            this.trackBar1.Orientation = System.Windows.Forms.Orientation.Vertical;
            this.trackBar1.Size = new System.Drawing.Size(45, 439);
            this.trackBar1.TabIndex = 0;
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.SCAN);
            this.panel1.Controls.Add(this.SSTF);
            this.panel1.Controls.Add(this.FCFS);
            this.panel1.Location = new System.Drawing.Point(164, 12);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(200, 94);
            this.panel1.TabIndex = 1;
            // 
            // FCFS
            // 
            this.FCFS.AutoSize = true;
            this.FCFS.Checked = true;
            this.FCFS.Location = new System.Drawing.Point(58, 16);
            this.FCFS.Name = "FCFS";
            this.FCFS.Size = new System.Drawing.Size(127, 17);
            this.FCFS.TabIndex = 3;
            this.FCFS.TabStop = true;
            this.FCFS.Text = "First Come First Serve";
            this.FCFS.UseVisualStyleBackColor = true;
            // 
            // SSTF
            // 
            this.SSTF.AutoSize = true;
            this.SSTF.Location = new System.Drawing.Point(58, 39);
            this.SSTF.Name = "SSTF";
            this.SSTF.Size = new System.Drawing.Size(140, 17);
            this.SSTF.TabIndex = 4;
            this.SSTF.Text = "Shortest Seek Time First";
            this.SSTF.UseVisualStyleBackColor = true;
            // 
            // SCAN
            // 
            this.SCAN.AutoSize = true;
            this.SCAN.Location = new System.Drawing.Point(58, 65);
            this.SCAN.Name = "SCAN";
            this.SCAN.Size = new System.Drawing.Size(120, 17);
            this.SCAN.TabIndex = 5;
            this.SCAN.Text = "SCAN disk (elevator";
            this.SCAN.UseVisualStyleBackColor = true;
            // 
            // listboxQueue
            // 
            this.listboxQueue.FormattingEnabled = true;
            this.listboxQueue.Location = new System.Drawing.Point(70, 88);
            this.listboxQueue.Name = "listboxQueue";
            this.listboxQueue.Size = new System.Drawing.Size(76, 316);
            this.listboxQueue.TabIndex = 2;
            // 
            // textBoxSelected
            // 
            this.textBoxSelected.Location = new System.Drawing.Point(70, 51);
            this.textBoxSelected.Name = "textBoxSelected";
            this.textBoxSelected.Size = new System.Drawing.Size(76, 20);
            this.textBoxSelected.TabIndex = 3;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(376, 463);
            this.Controls.Add(this.textBoxSelected);
            this.Controls.Add(this.listboxQueue);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.trackBar1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TrackBar trackBar1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.RadioButton SCAN;
        private System.Windows.Forms.RadioButton SSTF;
        private System.Windows.Forms.RadioButton FCFS;
        private System.Windows.Forms.ListBox listboxQueue;
        private System.Windows.Forms.TextBox textBoxSelected;
    }
}

