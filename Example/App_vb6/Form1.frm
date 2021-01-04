VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "DD"
   ClientHeight    =   3795
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4815
   LinkTopic       =   "Form1"
   ScaleHeight     =   3795
   ScaleWidth      =   4815
   StartUpPosition =   3  '´°¿ÚÈ±Ê¡
   Begin VB.CommandButton Command2 
      Caption         =   "Stop"
      Height          =   615
      Left            =   3120
      TabIndex        =   6
      Top             =   2040
      Width           =   1215
   End
   Begin VB.Timer Timer1 
      Interval        =   3000
      Left            =   120
      Top             =   120
   End
   Begin VB.Frame Frame1 
      Height          =   3015
      Left            =   720
      TabIndex        =   1
      Top             =   360
      Width           =   1935
      Begin VB.OptionButton Option1 
         Caption         =   "Kbd tab"
         Height          =   375
         Index           =   3
         Left            =   360
         TabIndex        =   5
         TabStop         =   0   'False
         Top             =   1740
         Width           =   1335
      End
      Begin VB.OptionButton Option1 
         Caption         =   "Mouse wheel"
         Height          =   375
         Index           =   2
         Left            =   360
         TabIndex        =   4
         TabStop         =   0   'False
         Top             =   1320
         Width           =   1335
      End
      Begin VB.OptionButton Option1 
         Caption         =   "Mouse click"
         Height          =   375
         Index           =   1
         Left            =   360
         TabIndex        =   3
         TabStop         =   0   'False
         Top             =   900
         Width           =   1335
      End
      Begin VB.OptionButton Option1 
         Caption         =   "Mouse  move"
         Height          =   375
         Index           =   0
         Left            =   360
         TabIndex        =   2
         TabStop         =   0   'False
         Top             =   480
         Width           =   1335
      End
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Start"
      Height          =   615
      Left            =   3120
      TabIndex        =   0
      Top             =   720
      Width           =   1215
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'1.Simple
Private Declare Function DD_mov Lib "DD94687.32.dll" (ByVal x As Long, ByVal y As Long) As Long
Private Declare Function DD_btn Lib "DD94687.32.dll" (ByVal btn As Long) As Long
Private Declare Function DD_whl Lib "DD94687.32.dll" (ByVal whl As Long) As Long
Private Declare Function DD_key Lib "DD94687.32.dll" (ByVal key As Long, ByVal flag As Long) As Long
Private Declare Function DD_str Lib "DD94687.32.dll" (ByVal str As String) As Long
Private Declare Function DD_movR Lib "DD94687.32.dll" (ByVal dx As Long, ByVal dy As Long) As Long

'2.General
'Private Declare Function DD_mov Lib "DD32.dll" (ByVal x As Long, ByVal y As Long) As Long
'Private Declare Function DD_btn Lib "DD32.dll" (ByVal btn As Long) As Long
'Private Declare Function DD_whl Lib "DD32.dll" (ByVal whl As Long) As Long
'Private Declare Function DD_key Lib "DD32.dll" (ByVal key As Long, ByVal flag As Long) As Long
'Private Declare Function DD_str Lib "DD32.dll" (ByVal str As String) As Long
'Private Declare Function DD_movR Lib "DD32.dll" (ByVal dx As Long, ByVal dy As Long) As Long

'HID
'Private Declare Function DD_mov Lib "DDHID32.dll" (ByVal x As Long, ByVal y As Long) As Long
'Private Declare Function DD_btn Lib "DDHID32.dll" (ByVal btn As Long) As Long
'Private Declare Function DD_whl Lib "DDHID32.dll" (ByVal whl As Long) As Long
'Private Declare Function DD_key Lib "DDHID32.dll" (ByVal key As Long, ByVal flag As Long) As Long
'Private Declare Function DD_str Lib "DDHID32.dll" (ByVal str As String) As Long
'Private Declare Function DD_movR Lib "DDHID32.dll" (ByVal dx As Long, ByVal dy As Long) As Long

Private Declare Sub Sleep Lib "kernel32.DLL" (ByVal dwMilliseconds As Long)
Dim sel As Integer

'start
Private Sub Command1_Click()
  Timer1.Enabled = True
  Command1.Enabled = False
  Command2.Enabled = True
End Sub

'stop
Private Sub Command2_Click()
  Timer1.Enabled = False
  Command1.Enabled = True
  Command2.Enabled = False
End Sub

Private Sub Form_Load()
  Dim ret As Long
  ret = DD_btn(0)
  If ret = 1 Then
    MsgBox ("Initialize OK")
    Command1.Enabled = True
    Command2.Enabled = False
  End If

End Sub

Private Sub Option1_Click(Index As Integer)
  sel = Index + 1
End Sub

Private Sub Timer1_Timer()
  Dim ret As Long
 
  Select Case sel
   Case 1
    'ret = DD_mov(20, 20) 'abs.
    ret = DD_movR(20, 20) 'rel.
   Case 2
  '1==L.down, 2==L.up, 4==R.down, 8==R.up, 16==M.down, 32==M.up
    ret = DD_btn(1)    'LefttClick
    Sleep (50)
    ret = DD_btn(2)
  
    'ret = DD_btn(4)   'RightClick
    'ret = DD_btn(8)

   Case 3
    ret = DD_whl(1)      'wheel up
    ret = DD_whl(2)     'wheelx down
   
   Case 4
    ret = DD_key(300, 1)  'tab==300, 1==down, 2==up
    Sleep (60)
    ret = DD_key(300, 2)
   
   Case 5
    'ret = DD_str("!@# ,./")  '
    
 End Select
 
 
End Sub



