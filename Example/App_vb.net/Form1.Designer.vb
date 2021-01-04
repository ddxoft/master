<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form 重写 Dispose，以清理组件列表。
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Windows 窗体设计器所必需的
    Private components As System.ComponentModel.IContainer

    '注意: 以下过程是 Windows 窗体设计器所必需的
    '可以使用 Windows 窗体设计器修改它。
    '不要使用代码编辑器修改它。
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Me.radioButton2 = New System.Windows.Forms.RadioButton()
        Me.radioButton1 = New System.Windows.Forms.RadioButton()
        Me.button1 = New System.Windows.Forms.Button()
        Me.timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.radioButton3 = New System.Windows.Forms.RadioButton()
        Me.button_start = New System.Windows.Forms.Button()
        Me.LinkLabel1 = New System.Windows.Forms.LinkLabel()
        Me.GroupBox1 = New System.Windows.Forms.GroupBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.RadioButton4 = New System.Windows.Forms.RadioButton()
        Me.TextBox1 = New System.Windows.Forms.TextBox()
        Me.GroupBox1.SuspendLayout()
        Me.SuspendLayout()
        '
        'radioButton2
        '
        Me.radioButton2.AutoSize = True
        Me.radioButton2.Checked = True
        Me.radioButton2.Location = New System.Drawing.Point(140, 19)
        Me.radioButton2.Margin = New System.Windows.Forms.Padding(2)
        Me.radioButton2.Name = "radioButton2"
        Me.radioButton2.Size = New System.Drawing.Size(83, 16)
        Me.radioButton2.TabIndex = 8
        Me.radioButton2.TabStop = True
        Me.radioButton2.Text = "MouseClick"
        Me.radioButton2.UseVisualStyleBackColor = True
        '
        'radioButton1
        '
        Me.radioButton1.AutoSize = True
        Me.radioButton1.Location = New System.Drawing.Point(140, 58)
        Me.radioButton1.Margin = New System.Windows.Forms.Padding(2)
        Me.radioButton1.Name = "radioButton1"
        Me.radioButton1.Size = New System.Drawing.Size(89, 16)
        Me.radioButton1.TabIndex = 7
        Me.radioButton1.Text = "KeyboardTab"
        Me.radioButton1.UseVisualStyleBackColor = True
        '
        'button1
        '
        Me.button1.Location = New System.Drawing.Point(152, 64)
        Me.button1.Name = "button1"
        Me.button1.Size = New System.Drawing.Size(147, 23)
        Me.button1.TabIndex = 5
        Me.button1.Text = "DD"
        Me.button1.UseVisualStyleBackColor = True
        '
        'timer1
        '
        Me.timer1.Interval = 5000
        '
        'radioButton3
        '
        Me.radioButton3.AutoSize = True
        Me.radioButton3.Location = New System.Drawing.Point(241, 19)
        Me.radioButton3.Margin = New System.Windows.Forms.Padding(2)
        Me.radioButton3.Name = "radioButton3"
        Me.radioButton3.Size = New System.Drawing.Size(77, 16)
        Me.radioButton3.TabIndex = 9
        Me.radioButton3.Text = "MouseMove"
        Me.radioButton3.UseVisualStyleBackColor = True
        '
        'button_start
        '
        Me.button_start.Location = New System.Drawing.Point(188, 280)
        Me.button_start.Name = "button_start"
        Me.button_start.Size = New System.Drawing.Size(75, 23)
        Me.button_start.TabIndex = 6
        Me.button_start.Text = "Start"
        Me.button_start.UseVisualStyleBackColor = True
        '
        'LinkLabel1
        '
        Me.LinkLabel1.AutoSize = True
        Me.LinkLabel1.Location = New System.Drawing.Point(181, 319)
        Me.LinkLabel1.Name = "LinkLabel1"
        Me.LinkLabel1.Size = New System.Drawing.Size(89, 12)
        Me.LinkLabel1.TabIndex = 10
        Me.LinkLabel1.TabStop = True
        Me.LinkLabel1.Text = "www.ddxoft.com"
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.Label1)
        Me.GroupBox1.Controls.Add(Me.RadioButton4)
        Me.GroupBox1.Controls.Add(Me.radioButton2)
        Me.GroupBox1.Controls.Add(Me.radioButton3)
        Me.GroupBox1.Controls.Add(Me.radioButton1)
        Me.GroupBox1.Location = New System.Drawing.Point(48, 113)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(355, 149)
        Me.GroupBox1.TabIndex = 11
        Me.GroupBox1.TabStop = False
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(138, 89)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(113, 36)
        Me.Label1.TabIndex = 11
        Me.Label1.Text = "F8 -> *** " & Global.Microsoft.VisualBasic.ChrW(13) & Global.Microsoft.VisualBasic.ChrW(10) & Global.Microsoft.VisualBasic.ChrW(13) & Global.Microsoft.VisualBasic.ChrW(10) & "F9 -> ctrl+alt+del" & Global.Microsoft.VisualBasic.ChrW(13) & Global.Microsoft.VisualBasic.ChrW(10)
        '
        'RadioButton4
        '
        Me.RadioButton4.AutoSize = True
        Me.RadioButton4.Location = New System.Drawing.Point(23, 19)
        Me.RadioButton4.Margin = New System.Windows.Forms.Padding(2)
        Me.RadioButton4.Name = "RadioButton4"
        Me.RadioButton4.Size = New System.Drawing.Size(83, 16)
        Me.RadioButton4.TabIndex = 10
        Me.RadioButton4.Text = "MouseWheel"
        Me.RadioButton4.UseVisualStyleBackColor = True
        '
        'TextBox1
        '
        Me.TextBox1.Location = New System.Drawing.Point(48, 30)
        Me.TextBox1.Name = "TextBox1"
        Me.TextBox1.Size = New System.Drawing.Size(355, 21)
        Me.TextBox1.TabIndex = 12
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(450, 346)
        Me.Controls.Add(Me.TextBox1)
        Me.Controls.Add(Me.GroupBox1)
        Me.Controls.Add(Me.LinkLabel1)
        Me.Controls.Add(Me.button1)
        Me.Controls.Add(Me.button_start)
        Me.Name = "Form1"
        Me.Text = "DD"
        Me.GroupBox1.ResumeLayout(False)
        Me.GroupBox1.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Private WithEvents radioButton2 As System.Windows.Forms.RadioButton
    Private WithEvents radioButton1 As System.Windows.Forms.RadioButton
    Private WithEvents button1 As System.Windows.Forms.Button
    Private WithEvents timer1 As System.Windows.Forms.Timer
    Private WithEvents radioButton3 As System.Windows.Forms.RadioButton
    Private WithEvents button_start As System.Windows.Forms.Button
    Friend WithEvents LinkLabel1 As System.Windows.Forms.LinkLabel
    Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents TextBox1 As System.Windows.Forms.TextBox
    Private WithEvents RadioButton4 As System.Windows.Forms.RadioButton
    Friend WithEvents Label1 As Label
End Class
