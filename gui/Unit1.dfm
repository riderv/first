object Form1: TForm1
  Left = 743
  Top = 167
  Width = 675
  Height = 592
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 64
    Top = 40
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 32
    Top = 88
    Width = 553
    Height = 417
    Lines.Strings = (
      'Memo1')
    TabOrder = 1
  end
  object Edit1: TEdit
    Left = 144
    Top = 40
    Width = 121
    Height = 21
    TabOrder = 2
    Text = 'Edit1'
  end
end
