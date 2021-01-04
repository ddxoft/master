unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls, ExtDlgs;

type
  TForm1 = class(TForm)
    Timer1: TTimer;
    GroupBox1: TGroupBox;
    RadioButton1: TRadioButton;
    RadioButton2: TRadioButton;
    RadioButton3: TRadioButton;
    RadioButton4: TRadioButton;
    Button2: TButton;
    Button1: TButton;
    Edit1: TEdit;
    Button3: TButton;
    OpenDialog1: TOpenDialog;
    procedure FormCreate(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure Button2Click(Sender: TObject);
    procedure RadioButton1Click(Sender: TObject);
    procedure RadioButton2Click(Sender: TObject);
    procedure RadioButton3Click(Sender: TObject);
    procedure RadioButton4Click(Sender: TObject);

    procedure Timer1Timer(Sender: TObject);
    procedure Button1Click(Sender: TObject);

    procedure Button3Click(Sender: TObject);
    procedure GetDDFunAddress();

  private
    { Private declarations }

  public
    { Public declarations }
  end;

  //DD Function
  TDD_todc = function(vkcode:integer):integer;stdcall;
  TDD_mov = function(x,y:integer):integer;stdcall;
  TDD_btn = function(btn:integer):integer;stdcall;
  TDD_whl = function(whl:integer):integer;stdcall;
  TDD_key = function(key,flag:integer):integer;stdcall;
  TDD_str = function(str:AnsiString):integer;stdcall;
  TDD_movR = function(dx,dy:integer):integer;stdcall;
var
  Form1: TForm1;

var
  DD:Thandle;

  DD_todc:TDD_todc;
  DD_mov:TDD_mov;
  DD_btn:TDD_btn;
  DD_whl:TDD_whl;
  DD_key:TDD_key;
  DD_str:TDD_str;
  DD_movR:TDD_movR;

  select:integer;
implementation

{$R *.dfm}

procedure TForm1.FormCreate(Sender: TObject);

begin
  Button2.Enabled:=false;
  Button1.Enabled:=false;
end;

procedure TForm1.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  if DD  <> 0 then
  begin
    freelibrary(DD );
  end;

  Timer1.Enabled := false;

end;

procedure TForm1.Button2Click(Sender: TObject);
begin
   Timer1.Enabled := false;
   Button1.Enabled:=true;
   Button2.Enabled:=false;
end;

procedure TForm1.Button3Click(Sender: TObject);
var
  filename:PChar;

begin
  if OpenDialog1.Execute then
  begin
    filename:= PChar(OpenDialog1.FileName);
    Edit1.Text:=filename;

    DD:=Loadlibrary( filename);  //x86 -> *32.dll , x64 -> *.64.dll

    if (DD  <> 0)  then
    begin
        MessageBox(0,'Load OK','info',MB_ICONASTERISK);
        GetDDFunAddress();
    end
    else
    begin
        MessageBox(0,'Load Error','info',MB_ICONASTERISK);
    end;
  end;
end;

procedure TForm1.RadioButton1Click(Sender: TObject);
begin
 select:=1;
end;

procedure TForm1.RadioButton2Click(Sender: TObject);
begin
 select:=2;
end;

procedure TForm1.RadioButton3Click(Sender: TObject);
begin
 select:=3;
end;

procedure TForm1.RadioButton4Click(Sender: TObject);
begin
 select:=4;
end;

procedure TForm1.Timer1Timer(Sender: TObject);
var
  ddcode :integer;
begin
   case select of
     1:
     begin
       DD_movR(20,20);     //Mouse Move rel.
       sleep(1000);
       DD_mov(100,100);    //Mouse Move abs.
     end;
     2:
     begin                    //Mouse LeftClick.
          DD_btn(1);          //1==L.down, 2==L.up, 4==R.down, 8==R.up, 16==M.down, 32==M.up
          sleep(50);          //may, delay 50ms,
          DD_btn(2);
     end;

     3:                       //Mouse Wheel. 1==down, 2==up
     begin
          DD_whl(1);
          DD_whl(2);
     end;

     4:
     begin
          ddcode := 300;              // TAB is 300 in ddcode.
          ddcode := DD_todc(VK_TAB);  //or by VK code
          DD_key(ddcode,1);           //1==down£¬2==up
          sleep(60);                  //may, delay 1-120ms,
          DD_key(ddcode,2);
     end;

     //5:  DD_str('KeyBorad !@#*| ');

   end;
end;

procedure TForm1.Button1Click(Sender: TObject);
begin
  Timer1.Enabled := true;
  Button2.Enabled:=true;
  Button1.Enabled:=false;
end;

procedure TForm1.GetDDFunAddress();
var
  st:integer;
begin
  @DD_mov:=nil;  //Mouse move abs.
  @DD_movR:=nil; //Mouse move rel.
  @DD_btn:=nil;  //Mouse button
  @DD_whl:=nil;  //Mouse wheel
  @DD_key:=nil;  //Keyboard
  @DD_str:=nil;  //Input visible char
  @DD_todc:=nil; //VK to ddcode


 if DD <> 0 then
 begin
    @DD_mov:=GetprocAddress(dd,'DD_mov');
    @DD_btn:=GetprocAddress(dd,'DD_btn');
    @DD_whl:=GetprocAddress(dd,'DD_whl');
    @DD_key:=GetprocAddress(dd,'DD_key');
    @DD_str:=GetprocAddress(dd,'DD_str');
    @DD_movR:=GetprocAddress(dd,'DD_movR');
    @DD_todc:=GetprocAddress(dd,'DD_todc');
    if ( Assigned(@DD_mov) and Assigned(@DD_btn) and
         Assigned(@DD_whl) and Assigned(@DD_key) and
         Assigned(@DD_str) and Assigned(@DD_movR)and  Assigned(@DD_todc))then
    begin
      st := DD_btn(0);//DD Initialize
      if st=1 then
      begin
        MessageBox(0,'OK','info',MB_ICONASTERISK);
        button1.Enabled := true;
      end
      else
      begin
        MessageBox(0,'Error','info',MB_ICONASTERISK);
      end;
    end;

 end;

end;

end.

