namespace KPO_LR3
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
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.создатьСписокToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.добавитьЭлементToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.переборКнопокToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.создатьЭнумераторToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.moveNextToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.currentToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.resetToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.переборОбъектовToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.создатьЭнумераторToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.moveNextToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.currentToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.resetToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.panel1 = new System.Windows.Forms.Panel();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.menuStrip1.SuspendLayout();
            this.statusStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.создатьСписокToolStripMenuItem,
            this.добавитьЭлементToolStripMenuItem,
            this.переборКнопокToolStripMenuItem,
            this.переборОбъектовToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(671, 28);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // создатьСписокToolStripMenuItem
            // 
            this.создатьСписокToolStripMenuItem.Name = "создатьСписокToolStripMenuItem";
            this.создатьСписокToolStripMenuItem.Size = new System.Drawing.Size(130, 24);
            this.создатьСписокToolStripMenuItem.Text = "Создать список";
            this.создатьСписокToolStripMenuItem.Click += new System.EventHandler(this.создатьСписокToolStripMenuItem_Click);
            // 
            // добавитьЭлементToolStripMenuItem
            // 
            this.добавитьЭлементToolStripMenuItem.Name = "добавитьЭлементToolStripMenuItem";
            this.добавитьЭлементToolStripMenuItem.Size = new System.Drawing.Size(151, 24);
            this.добавитьЭлементToolStripMenuItem.Text = "Добавить элемент";
            this.добавитьЭлементToolStripMenuItem.Click += new System.EventHandler(this.добавитьЭлементToolStripMenuItem_Click);
            // 
            // переборКнопокToolStripMenuItem
            // 
            this.переборКнопокToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.создатьЭнумераторToolStripMenuItem,
            this.moveNextToolStripMenuItem,
            this.currentToolStripMenuItem,
            this.resetToolStripMenuItem});
            this.переборКнопокToolStripMenuItem.Name = "переборКнопокToolStripMenuItem";
            this.переборКнопокToolStripMenuItem.Size = new System.Drawing.Size(140, 24);
            this.переборКнопокToolStripMenuItem.Text = "Перебор кнопок";
            // 
            // создатьЭнумераторToolStripMenuItem
            // 
            this.создатьЭнумераторToolStripMenuItem.Name = "создатьЭнумераторToolStripMenuItem";
            this.создатьЭнумераторToolStripMenuItem.Size = new System.Drawing.Size(234, 26);
            this.создатьЭнумераторToolStripMenuItem.Text = "Создать энумератор";
            this.создатьЭнумераторToolStripMenuItem.Click += new System.EventHandler(this.создатьЭнумераторToolStripMenuItem_Click);
            // 
            // moveNextToolStripMenuItem
            // 
            this.moveNextToolStripMenuItem.Name = "moveNextToolStripMenuItem";
            this.moveNextToolStripMenuItem.Size = new System.Drawing.Size(234, 26);
            this.moveNextToolStripMenuItem.Text = "MoveNext";
            this.moveNextToolStripMenuItem.Click += new System.EventHandler(this.moveNextToolStripMenuItem_Click);
            // 
            // currentToolStripMenuItem
            // 
            this.currentToolStripMenuItem.Name = "currentToolStripMenuItem";
            this.currentToolStripMenuItem.Size = new System.Drawing.Size(234, 26);
            this.currentToolStripMenuItem.Text = "Current";
            this.currentToolStripMenuItem.Click += new System.EventHandler(this.currentToolStripMenuItem_Click);
            // 
            // resetToolStripMenuItem
            // 
            this.resetToolStripMenuItem.Name = "resetToolStripMenuItem";
            this.resetToolStripMenuItem.Size = new System.Drawing.Size(234, 26);
            this.resetToolStripMenuItem.Text = "Reset";
            this.resetToolStripMenuItem.Click += new System.EventHandler(this.resetToolStripMenuItem_Click);
            // 
            // переборОбъектовToolStripMenuItem
            // 
            this.переборОбъектовToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.создатьЭнумераторToolStripMenuItem1,
            this.moveNextToolStripMenuItem1,
            this.currentToolStripMenuItem1,
            this.resetToolStripMenuItem1});
            this.переборОбъектовToolStripMenuItem.Name = "переборОбъектовToolStripMenuItem";
            this.переборОбъектовToolStripMenuItem.Size = new System.Drawing.Size(155, 24);
            this.переборОбъектовToolStripMenuItem.Text = "Перебор объектов";
            // 
            // создатьЭнумераторToolStripMenuItem1
            // 
            this.создатьЭнумераторToolStripMenuItem1.Name = "создатьЭнумераторToolStripMenuItem1";
            this.создатьЭнумераторToolStripMenuItem1.Size = new System.Drawing.Size(234, 26);
            this.создатьЭнумераторToolStripMenuItem1.Text = "Создать энумератор";
            this.создатьЭнумераторToolStripMenuItem1.Click += new System.EventHandler(this.создатьЭнумераторToolStripMenuItem1_Click);
            // 
            // moveNextToolStripMenuItem1
            // 
            this.moveNextToolStripMenuItem1.Name = "moveNextToolStripMenuItem1";
            this.moveNextToolStripMenuItem1.Size = new System.Drawing.Size(234, 26);
            this.moveNextToolStripMenuItem1.Text = "MoveNext";
            this.moveNextToolStripMenuItem1.Click += new System.EventHandler(this.moveNextToolStripMenuItem1_Click);
            // 
            // currentToolStripMenuItem1
            // 
            this.currentToolStripMenuItem1.Name = "currentToolStripMenuItem1";
            this.currentToolStripMenuItem1.Size = new System.Drawing.Size(234, 26);
            this.currentToolStripMenuItem1.Text = "Current";
            this.currentToolStripMenuItem1.Click += new System.EventHandler(this.currentToolStripMenuItem1_Click);
            // 
            // resetToolStripMenuItem1
            // 
            this.resetToolStripMenuItem1.Name = "resetToolStripMenuItem1";
            this.resetToolStripMenuItem1.Size = new System.Drawing.Size(234, 26);
            this.resetToolStripMenuItem1.Text = "Reset";
            this.resetToolStripMenuItem1.Click += new System.EventHandler(this.resetToolStripMenuItem1_Click);
            // 
            // panel1
            // 
            this.panel1.AutoScroll = true;
            this.panel1.Location = new System.Drawing.Point(12, 31);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(553, 196);
            this.panel1.TabIndex = 1;
            // 
            // statusStrip1
            // 
            this.statusStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatusLabel1});
            this.statusStrip1.Location = new System.Drawing.Point(0, 343);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(671, 22);
            this.statusStrip1.TabIndex = 2;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(0, 16);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(671, 365);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem создатьСписокToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem добавитьЭлементToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem переборКнопокToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem переборОбъектовToolStripMenuItem;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
        private System.Windows.Forms.ToolStripMenuItem создатьЭнумераторToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem moveNextToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem currentToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem resetToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem создатьЭнумераторToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem moveNextToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem currentToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem resetToolStripMenuItem1;
    }
}

