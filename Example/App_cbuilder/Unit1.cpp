//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
   OpenDialog1->Filter = "DD(*.dll)|*.dll";
    OpenDialog1->DefaultExt = ".dll";
         if (this->OpenDialog1->Execute()) {
	this->Edit1->Text = OpenDialog1->FileName;
        AnsiString strM; strM = Edit1->Text;
		hinst = LoadLibraryW(this->Edit1->Text.w_str());

        this->Button2->Enabled = false;


		if (!hinst) {
		ShowMessage("Load Dll error");
	    return;
	}

	dd_todc = (lpfun_DD_todc)GetProcAddress(hinst, "DD_todc");
	dd_btn = (lpfun_DD_btn)GetProcAddress(hinst, "DD_btn");
	dd_mov = (lpfun_DD_mov)GetProcAddress(hinst, "DD_mov");
	dd_movR = (lpfun_DD_mov)GetProcAddress(hinst, "DD_movR");
	dd_whl = (lpfun_DD_whl)GetProcAddress(hinst, "DD_whl");
	dd_key = (lpfun_DD_key)GetProcAddress(hinst, "DD_key");
	dd_str = (lpfun_DD_str)GetProcAddress(hinst, "DD_str");

        if (dd_todc && dd_movR && dd_btn && dd_mov && dd_whl && dd_key && dd_str)
	{
		int st = dd_btn(0); //DD Initialize
		if(st == 1){
			this->Button2->Enabled = true;
			ShowMessage("OK");
        }
	}
	else {
		ShowMessage("Error");
	}

        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
if (this->Button2->Caption == "Start") {
	this->Button2->Caption = "Stop";
	this->Timer1->Enabled = true;
    }
    else {
	this->Button2->Caption = "Start";
	this->Timer1->Enabled = false;
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
                    if (this->Timer1->Enabled) {
	this->Timer1->Enabled = false;
    }
    if (hinst) {
	FreeLibrary(hinst);
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer1Timer(TObject *Sender)
{

    int ret =0;

  switch (select) {

	case 1:
	   {
		int ddcode = 300;            // TAB is 300 in ddcode.
		ddcode = dd_todc(VK_TAB);    //or by VK code

		dd_key(ddcode, 1);           //1==down£¬2==up
		Sleep(50);					 //may, delay 1-120ms,
		dd_key(ddcode, 2);
	   }
		case 2:
		dd_btn(1);         //1==L.down, 2==L.up, 4==R.down, 8==R.up, 16==M.down, 32==M.up
		Sleep(8);
		dd_btn(2);
	break;
	//dd_movR(10, 10);     //Mouse Move rel.
	//dd_mov(100, 100);    //Mouse Move abs.
	//ret = dd_whl(1);     //Mouse Wheel. 1==down, 2==up
	//ret = dd_whl(2);
	   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
  select=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
  select=2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
  select=0;
}
//---------------------------------------------------------------------------

