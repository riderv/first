//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uForm1Impl.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1 = 0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}

typedef void (__stdcall *onPaint_t)();
onPaint_t onPaint1 = 0;




extern "C" {  //---------------------------------------------------------------------------


__declspec( dllexport )
HWND __stdcall CreateForm(onPaint_t p1)
{
 try{
    onPaint1 = p1;
    Application->Initialize();
    Application->CreateForm(__classid(TForm1), &Form1);
    return Form1->Handle;
 }
 catch(...){
    return NULL;
 }
}

__declspec( dllexport )
HWND __stdcall GetPanel()
{
 try
 {
    return Form1->Panel1->Handle;
 }
 catch(...)
 {
    return NULL;
 }
}
__declspec( dllexport )
void __stdcall FreeForm()
{
 try{
    delete Form1;
    Form1 = 0;
 }catch(...){}
}

__declspec( dllexport )
void __stdcall Run()
{
 try
 {
    Application->Run();
 } catch(...) { }
}

}// C ---------------------------------------------------------------------------



//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormPaint(TObject *Sender)
{
//

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    //Repaint();
        if( onPaint1 )
            onPaint1();
}
//---------------------------------------------------------------------------
