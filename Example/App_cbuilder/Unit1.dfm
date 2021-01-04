object Form1: TForm1
  Left = 192
  Top = 198
  Caption = 'DD'
  ClientHeight = 306
  ClientWidth = 338
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 136
    Top = 48
    Width = 75
    Height = 25
    Caption = 'load'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 16
    Top = 24
    Width = 305
    Height = 21
    TabOrder = 1
    Text = 'dd dll'
  end
  object Button2: TButton
    Left = 136
    Top = 184
    Width = 75
    Height = 25
    Caption = 'Start'
    Enabled = False
    TabOrder = 2
    OnClick = Button2Click
  end
  object RadioButton1: TRadioButton
    Left = 127
    Top = 101
    Width = 113
    Height = 17
    Caption = 'Keyboard TAB'
    TabOrder = 3
    OnClick = RadioButton1Click
  end
  object RadioButton2: TRadioButton
    Left = 127
    Top = 133
    Width = 113
    Height = 17
    Caption = 'Mouse Click'
    TabOrder = 4
    OnClick = RadioButton2Click
  end
  object OpenDialog1: TOpenDialog
    Left = 16
    Top = 264
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 3000
    OnTimer = Timer1Timer
    Left = 64
    Top = 264
  end
end
