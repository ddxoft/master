Public Class Form1
    Private dd As CDD

    Private Sub Form1_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load
        Me.RegHotKey()
        Me.GroupBox1.Enabled = False
        Me.button_start.Enabled = False
        dd = New CDD
    End Sub

    Private Sub Form1_FormClosing(ByVal sender As Object, ByVal e As System.Windows.Forms.FormClosingEventArgs) Handles Me.FormClosing
        Me.UnRegHotKey()
    End Sub

    Private Sub button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles button1.Click
        Dim ofd As New OpenFileDialog()
        ofd.Filter = "DD dll|*.DLL"

        If ofd.ShowDialog() <> DialogResult.OK Then Return

        'x86 -> * 32.dll
        'x64 -> *.64.dll
        'AnyCpu -> Error
        'Maybe not  run in vs, make to exe for test.
        LoadDD(ofd.FileName)
    End Sub

    Private Sub button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles button_start.Click
        If button_start.Text = "Start" Then
            button_start.Text = "Stop"
            timer1.Enabled = True
        Else
            button_start.Text = "Start"
            timer1.Enabled = False
        End If
    End Sub

    Private Sub timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles timer1.Tick
        If radioButton1.Checked = True Then
            Dim ddcode As Int32 = 300                      'tab == 300 in ddcode
            dd.key(ddcode, 1)                                     ' 1=down 2=up
            System.Threading.Thread.Sleep(50)           'may, delay 50ms
            dd.key(ddcode, 2)
            Exit Sub
        End If

        If radioButton2.Checked = True Then
            '1==L.down, 2==L.up, 4==R.down, 8==R.up, 16==M.down, 32==M.up
            dd.btn(1)
            System.Threading.Thread.Sleep(50)
            dd.btn(2)
            Exit Sub
        End If

        If radioButton3.Checked = True Then
            dd.movR(20, 20)   'move rel.
            dd.mov(200, 200) 'move abs.
            Exit Sub
        End If

        If RadioButton4.Checked = True Then
            dd.whl(1)
            System.Threading.Thread.Sleep(200)
            dd.whl(2)
        End If
    End Sub

    Private Sub LinkLabel1_LinkClicked(ByVal sender As System.Object, ByVal e As System.Windows.Forms.LinkLabelLinkClickedEventArgs) Handles LinkLabel1.LinkClicked
        Dim url As String = "http://" & LinkLabel1.Text
        System.Diagnostics.Process.Start(url)
    End Sub

    Private Sub LoadDD(ByVal dllfile As String)
        Me.button_start.Enabled = False
        Me.GroupBox1.Enabled = False

        Dim ret As Int32 = dd.Load(dllfile)

        If ret = -2 Then MessageBox.Show("Error2") : Exit Sub
        If ret = -1 Then MessageBox.Show("Error1") : Exit Sub

        If ret = 1 Then
            ret = dd.btn(0) 'DD Initialize
            If ret = 1 Then
                MessageBox.Show("DD OK！")
            Else
                MessageBox.Show("DD Error " & ret.ToString)
            End If
        End If

        Me.button_start.Enabled = True
        Me.GroupBox1.Enabled = True
        Me.TextBox1.Text = dllfile
    End Sub

#Region "hotkey"
    Private Declare Function RegisterHotKey Lib "user32" (ByVal hwnd As IntPtr, ByVal id As Integer, ByVal fsModifiers As KeyModifiers, ByVal vk As Integer) As Integer
    Private Declare Function UnregisterHotKey Lib "user32" (ByVal hwnd As IntPtr, ByVal id As Integer) As Integer

    Private Sub RegHotKey()
        RegisterHotKey(Me.Handle, 80, 0, Keys.F8)
        RegisterHotKey(Me.Handle, 90, 0, Keys.F9)
    End Sub

    Private Sub UnRegHotKey()
        UnregisterHotKey(Me.Handle, 80)
        UnregisterHotKey(Me.Handle, 90)
    End Sub

    Protected Overrides Sub WndProc(ByRef m As System.Windows.Forms.Message)
        Static WM_HOTKEY As Long = &H312  '表示消息来自用户自定义热键
        If m.Msg = WM_HOTKEY Then
            ProcessHotkey(m)
        End If
        MyBase.WndProc(m)
    End Sub
    Private Sub ProcessHotkey(ByVal m As Message)
        Select Case m.WParam.ToInt32
            Case 80
                Fun80()
            Case 90
                Fun90()
        End Select
    End Sub

    Private Sub Fun80()
        dd.str(" Keyboard char [A-Za_z] {@$} ") ' Type visiable char
    End Sub

    Private Sub Fun90()
        'CTRL+ALT+DEL
        If dd.key IsNot Nothing Then
            dd.key(600, 1)                                  'ctrl = 600 in ddcode
            dd.key(602, 1)                                  'alt  = 602
            dd.key(706, 1)                                  'del = 706
            System.Threading.Thread.Sleep(50)  '
            dd.key(706, 2)
            dd.key(602, 2)
            dd.key(600, 2)
        End If
    End Sub

#End Region


End Class
