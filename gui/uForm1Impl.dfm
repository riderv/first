object Form1: TForm1
  Left = 321
  Top = 128
  Width = 1013
  Height = 644
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  OnClose = FormClose
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 797
    Top = 0
    Width = 200
    Height = 606
    Align = alRight
    Caption = 'Panel1'
    TabOrder = 0
    object PaintBox1: TPaintBox
      Left = 7
      Top = 32
      Width = 65
      Height = 41
    end
    object Edit1: TEdit
      Left = 8
      Top = 8
      Width = 121
      Height = 21
      TabOrder = 0
      Text = 'Edit1'
    end
  end
  object Timer1: TTimer
    Interval = 33
    OnTimer = Timer1Timer
    Left = 72
    Top = 48
  end
end
