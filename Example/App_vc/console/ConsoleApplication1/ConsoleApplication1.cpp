#include "stdafx.h"
#include "ConsoleApplication1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

typedef int(*pDD_btn)(int btn);
typedef int(*pDD_whl)(int whl);
typedef int(*pDD_key)(int keycode, int flag);
typedef int(*pDD_mov)(int x, int y);
typedef int(*pDD_str)(char *str);
typedef int(*pDD_todc)(int vk);
typedef int(*pDD_movR)(int dx, int dy);

pDD_btn      DD_btn;          //Mouse button
pDD_whl      DD_whl;		     //Mouse wheel
pDD_key      DD_key;		     //Mouse move abs.
pDD_mov    DD_mov;		 //Mouse move rel.
pDD_str       DD_str;			 //Keyboard
pDD_todc    DD_todc;		 //Input visible char
pDD_movR   DD_movR;	     //VK to ddcode

int main()
{
	std::cout << "DD!\n";
	system("pause");

	HMODULE hDll = LoadLibraryW(L"X:\\DD94687.64.dll");    //App x64
	//HMODULE hDll = LoadLibraryW(L"X:\\DD94687.32.dll"); //App x86

	if (hDll == nullptr)
	{
		return -1;
	}

	DD_btn = (pDD_btn)GetProcAddress(hDll, "DD_btn");
	DD_whl = (pDD_whl)GetProcAddress(hDll, "DD_whl");
	DD_key = (pDD_key)GetProcAddress(hDll, "DD_key");
	DD_mov = (pDD_mov)GetProcAddress(hDll, "DD_mov");
	DD_str = (pDD_str)GetProcAddress(hDll, "DD_str");
	DD_todc = (pDD_todc)GetProcAddress(hDll, "DD_todc");
	DD_movR = (pDD_movR)GetProcAddress(hDll, "DD_movR");

	if (!(DD_btn && DD_whl && DD_key && DD_mov && DD_str  && DD_todc && DD_movR))
	{
		return -2;
	}

	int st = DD_btn(0);
	if (st != 1)
	{
		//DD Initialize Error
		return st;
	}

	std::cout << "Mouse R.click";
	system("pause");
	//1==L.down, 2==L.up, 4==R.down, 8==R.up, 16==M.down, 32==M.up
	DD_btn(4);
	Sleep(50); //may, delay 50ms
	DD_btn(8);

	std::cout << "Mouse Move rel."; 
	system("pause");
	DD_movR(20, 20);   //move rel.
	std::cout << "Mouse Move abs.";
	system("pause");
	DD_mov(200, 200); //move abs.

	std::cout << "Keyboard L.win";
	system("pause");
	int ddcode = 601;		//Left.win == 601 in ddcode	   
	ddcode = DD_todc(VK_LWIN);
	DD_key(ddcode, 1);
	Sleep(1);					//may, delay 50ms
	DD_key(ddcode, 2);

	std::cout << "type visiable char";
	system("pause");
	DD_str("Keyboard char [A-Za_z] {@$} ");

	std::cout << "ctrl+alt+del";
	system("pause");
	DD_key(600, 1);  //600 == L.CTRL down
	DD_key(602, 1);  //602 == L.ALT   down
	DD_key(706, 1);  //706 == DEL   down
	DD_key(706, 2);
	DD_key(602, 2); 	 //up
	DD_key(600, 2);

	FreeLibrary(hDll);

	return 1;

}


