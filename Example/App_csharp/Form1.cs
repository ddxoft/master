using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace App_csharp
{
    public partial class Form1 : Form
    {
        private CDD dd;

        public Form1()
        {
            InitializeComponent();
        }
 
        private void Form1_Load(object sender, EventArgs e)
        {
            this.button_start.Enabled = false;

            reg_hotkey();                            // 注册热键

            dd = new CDD();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            unreg_hotkey();
        }
        
        private void timer1_Tick(object sender, EventArgs e)
        {
            if (radioButton1.Checked == true)     
            {
                int ddcode =  300; //tab == 300 in ddcode
                dd.key(ddcode, 1); //1=down
                System.Threading.Thread.Sleep(50);           //may, delay 50ms
                dd.key(ddcode, 2); //2 = up
                return;
            }

            if (radioButton2.Checked == true)   
            {
                //'1==L.down, 2==L.up, 4==R.down, 8==R.up, 16==M.down, 32==M.up
                dd.btn(1);
                System.Threading.Thread.Sleep(50);           //may, delay 50ms
                dd.btn(2);                                    
                return;
            }
                        
            if (radioButton3.Checked == true)   
            {
                dd.movR(20, 20);   //move rel.
                dd.mov(200, 200); //move abs.
                return;
            }
                   
            if (radioButton4.Checked == true) 
            {
                dd.whl(1);                                  //up
                System.Threading.Thread.Sleep(1000);
                dd.whl(2);                                  //down
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "DD|*.DLL";

            if (ofd.ShowDialog() != DialogResult.OK)
            {
                return;
            }

            //'x86 -> * 32.dll
            //'x64 -> *.64.dll
            //'AnyCpu -> Error
            //Maybe not run in vs, make to exe for test.
            LoadDllFile(ofd.FileName);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (button_start.Text == "Start")
            {
                button_start.Text = "Stop";
                timer1.Enabled = true;
            }
            else
            {
                button_start.Text = "Start";
                timer1.Enabled = false;
            }
        }
      
        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            string url = "http://" + linkLabel1.Text;
            System.Diagnostics.Process.Start(url);
        }

        private void LoadDllFile(string dllfile)
        {
            label1.Visible = false;
            label2.Visible = false;
            button_start.Enabled = false;


            int ret = dd.Load(dllfile);
            if (ret !=1) { MessageBox.Show("Load Error"); return; }


            ret = dd.btn(0); //DD Initialize
            if (ret != 1) { MessageBox.Show("Initialize Error"); return; }

            button_start.Enabled = true;
            label1.Visible = true;
            label2.Visible = true;

            textBox1.Text = dllfile;

            return;
        }


        #region "HotKey"
        [DllImport("user32.dll")]
        public static extern bool RegisterHotKey(
         IntPtr hWnd,
         int id,                            
         KeyModifiers modkey,    
         Keys vk                         
        );
        [DllImport("user32.dll")]
        public static extern bool UnregisterHotKey(
         IntPtr hWnd,              
         int id                          
        );

        void reg_hotkey()
        {
            RegisterHotKey(this.Handle, 80, 0, Keys.F8);
            RegisterHotKey(this.Handle, 90, 0, Keys.F9);
        }

        void unreg_hotkey()
        {
            UnregisterHotKey(this.Handle, 80);
            UnregisterHotKey(this.Handle, 90);
        }

        protected override void WndProc(ref Message m)
        {
            const int WM_HOTKEY = 0x0312;                      
            switch (m.Msg)
            {
                case WM_HOTKEY:
                    ProcessHotkey(m);                                     
                    break;
            }
            base.WndProc(ref m);
        }

        private void ProcessHotkey(Message msg)        
        {
            switch (msg.WParam.ToInt32())
            {
                case 80:
                    Fun80();
                    break;
                case 90:
                    Fun90();                                                        
                    break;
            }
        }

        private void Fun80()
        {
            dd.str("Keyboard char [A-Za_z] {@$} ");
        }

        private void Fun90()
        {
            if (dd.key != null)
            {
                //CTRL+ALT+DEL
                dd.key(600, 1);                                      //600 == L.CTRL down
                dd.key(602, 1);                                      // ALT   down
                dd.key(706, 1);                                      // DEL   down
                System.Threading.Thread.Sleep(5);
                dd.key(706, 2);                                       //up
                dd.key(602, 2);
                dd.key(600, 2);
            }
        }

        #endregion

    }
}

