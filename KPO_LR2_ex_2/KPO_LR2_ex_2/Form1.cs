using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace KPO_LR2_ex_2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        
        int space = 0;
        int defis = 0;
        bool allow_defis = true;
        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (Char.IsLetter(e.KeyChar) || (e.KeyChar == ' ') || (e.KeyChar == '-'))
                if (textBox1.SelectionStart == 0)
                    if (e.KeyChar == ' ') e.Handled = true;
                    else e.KeyChar = Char.ToUpper(e.KeyChar);
                else if (e.KeyChar == '-') if (allow_defis && defis == 0) defis = 1;
                                            else e.Handled = true;
                else if (e.KeyChar == ' ') if (space == 0) space = 1;
                                            else e.Handled = true;
                else if (space > 0) { e.KeyChar = Char.ToUpper(e.KeyChar); space++; }
                else if (defis > 0) { e.KeyChar = Char.ToUpper(e.KeyChar); defis = 0; allow_defis = false; }
                else { }
            else e.Handled = true;

        }

        private void textBox1_KeyUp(object sender, KeyEventArgs e)
        {
            if (space == 2)
            {
                textBox1.AppendText(".");
                textBox1.SelectionStart = textBox1.Text.Length;
                textBox1.SelectionLength = 0;
            }
            if (space == 3)
            {
                textBox1.AppendText(".");
                textBox1.SelectionStart = 0;
                textBox1.SelectionLength = textBox1.Text.Length;
                space = 0;
                defis = 0;
            };

        }
    }
}
