#pragma once

typedef int (FAR WINAPI *pDD_btn)(int btn);
typedef int (FAR WINAPI *pDD_whl)(int whl);
typedef int (FAR WINAPI *pDD_key)(int keycode,int flag);
typedef int (FAR WINAPI *pDD_mov)( int x,int y);
typedef int (FAR WINAPI *pDD_str)(PCHAR str);
typedef int (FAR WINAPI *pDD_todc)(int vk);
typedef int (FAR WINAPI *pDD_movR)( int dx,int dy);


class CDD
{
public:
	CDD(void);
	~CDD(void);
public:
	pDD_btn      DD_btn ;        //Mouse button
	pDD_whl      DD_whl ;		 //Mouse wheel
	pDD_key      DD_key ;		 //Mouse move abs.
	pDD_mov    DD_mov ;		 //Mouse move rel.
	pDD_str       DD_str;			 //Keyboard
	pDD_todc    DD_todc;		 //Input visible char
	pDD_movR   DD_movR ;	 //VK to ddcode


public:
	HINSTANCE m_hModule;
	int GetFunAddr(CString dllfile);

};
