namespace Decorator
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
            this.label1 = new System.Windows.Forms.Label();
            this.checkBoxAC = new System.Windows.Forms.CheckBox();
            this.checkBoxWheels = new System.Windows.Forms.CheckBox();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.buttonBuy = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(31, 23);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(28, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Ford";
            // 
            // checkBoxAC
            // 
            this.checkBoxAC.AutoSize = true;
            this.checkBoxAC.Location = new System.Drawing.Point(102, 28);
            this.checkBoxAC.Name = "checkBoxAC";
            this.checkBoxAC.Size = new System.Drawing.Size(105, 17);
            this.checkBoxAC.TabIndex = 1;
            this.checkBoxAC.Text = "Air Conditionning";
            this.checkBoxAC.UseVisualStyleBackColor = true;
            // 
            // checkBoxWheels
            // 
            this.checkBoxWheels.AutoSize = true;
            this.checkBoxWheels.Location = new System.Drawing.Point(102, 51);
            this.checkBoxWheels.Name = "checkBoxWheels";
            this.checkBoxWheels.Size = new System.Drawing.Size(62, 17);
            this.checkBoxWheels.TabIndex = 2;
            this.checkBoxWheels.Text = "Wheels";
            this.checkBoxWheels.UseVisualStyleBackColor = true;
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.Location = new System.Drawing.Point(12, 117);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(260, 95);
            this.listBox1.TabIndex = 4;
            // 
            // buttonBuy
            // 
            this.buttonBuy.Location = new System.Drawing.Point(107, 218);
            this.buttonBuy.Name = "buttonBuy";
            this.buttonBuy.Size = new System.Drawing.Size(75, 23);
            this.buttonBuy.TabIndex = 5;
            this.buttonBuy.Text = "Buy";
            this.buttonBuy.UseVisualStyleBackColor = true;
            this.buttonBuy.Click += new System.EventHandler(this.buttonBuy_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Controls.Add(this.buttonBuy);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.checkBoxWheels);
            this.Controls.Add(this.checkBoxAC);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.CheckBox checkBoxAC;
        private System.Windows.Forms.CheckBox checkBoxWheels;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Button buttonBuy;
    }
}

