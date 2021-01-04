//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TEdit *Edit1;
        TOpenDialog *OpenDialog1;
        TButton *Button2;
        TTimer *Timer1;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall RadioButton1Click(TObject *Sender);
        void __fastcall RadioButton2Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);

        HINSTANCE hinst;
          typedef int(__stdcall*lpfun_DD_todc)(int);
    typedef int(__stdcall*lpfun_DD_btn)(int btn);
    typedef int(__stdcall*lpfun_DD_mov)(int x, int y);
    typedef int(__stdcall*lpfun_DD_movR)(int dx, int dy);
    typedef int(__stdcall*lpfun_DD_whl)(int whl);
    typedef int(__stdcall*lpfun_DD_key)(int code, int flag);
    typedef int(__stdcall*lpfun_DD_str)(char* str);

  lpfun_DD_todc dd_todc;   //VK code to ddcode
  lpfun_DD_mov dd_movR;    //Mouse move rel.
  lpfun_DD_btn dd_btn;     //Mouse button
  lpfun_DD_mov dd_mov;     //Mouse move abs.
  lpfun_DD_whl dd_whl;     //Mouse wheel
  lpfun_DD_key dd_key;     //Keyboard
  lpfun_DD_str dd_str;     //Input visible char
  int select;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 