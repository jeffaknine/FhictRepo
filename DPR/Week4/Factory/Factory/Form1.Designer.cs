namespace Factory
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
            this.listBoxType = new System.Windows.Forms.ListBox();
            this.label2 = new System.Windows.Forms.Label();
            this.listBoxBrand = new System.Windows.Forms.ListBox();
            this.listBoxInfo = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // listBoxType
            // 
            this.listBoxType.FormattingEnabled = true;
            this.listBoxType.Location = new System.Drawing.Point(175, 30);
            this.listBoxType.Name = "listBoxType";
            this.listBoxType.Size = new System.Drawing.Size(124, 121);
            this.listBoxType.TabIndex = 1;
            this.listBoxType.SelectedIndexChanged += new System.EventHandler(this.listBoxType_SelectedIndexChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(41, 30);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(64, 13);
            this.label2.TabIndex = 2;
            this.label2.Text = "Select Type";
            // 
            // listBoxBrand
            // 
            this.listBoxBrand.FormattingEnabled = true;
            this.listBoxBrand.Location = new System.Drawing.Point(409, 30);
            this.listBoxBrand.Name = "listBoxBrand";
            this.listBoxBrand.Size = new System.Drawing.Size(130, 121);
            this.listBoxBrand.TabIndex = 3;
            this.listBoxBrand.SelectedIndexChanged += new System.EventHandler(this.listBoxBrand_SelectedIndexChanged);
            // 
            // listBoxInfo
            // 
            this.listBoxInfo.FormattingEnabled = true;
            this.listBoxInfo.Location = new System.Drawing.Point(647, 30);
            this.listBoxInfo.Name = "listBoxInfo";
            this.listBoxInfo.Size = new System.Drawing.Size(120, 121);
            this.listBoxInfo.TabIndex = 4;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(794, 529);
            this.Controls.Add(this.listBoxInfo);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.listBoxBrand);
            this.Controls.Add(this.listBoxType);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox listBoxType;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ListBox listBoxBrand;
        private System.Windows.Forms.ListBox listBoxInfo;
    }
}

