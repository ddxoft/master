#include "StdAfx.h"
#include "DD.h"

CDD::CDD(void)
{
	m_hModule = NULL;
}

CDD::~CDD(void)
{
	if (m_hModule)
	{
		::FreeLibrary(m_hModule);
	}
}

int CDD::GetFunAddr(CString dllfile)
{
	if ( -1 == ::GetFileAttributes(dllfile))
	{
		return -11;
	}

	m_hModule = ::LoadLibrary(dllfile);

	if ( m_hModule==NULL)
	{
		return -12; 
	}

	DD_btn = (pDD_btn )GetProcAddress(m_hModule,"DD_btn"); 
	DD_whl = (pDD_whl )GetProcAddress(m_hModule,"DD_whl"); 
	DD_key = (pDD_key )GetProcAddress(m_hModule,"DD_key"); 
	DD_mov = (pDD_mov)GetProcAddress(m_hModule,"DD_mov"); 
	DD_str  = (pDD_str)GetProcAddress(m_hModule,"DD_str"); 
	DD_todc  = (pDD_todc)GetProcAddress(m_hModule,"DD_todc"); 
	DD_movR = (pDD_movR)GetProcAddress(m_hModule,"DD_movR"); 

	if ( DD_btn && DD_whl && DD_key && DD_mov && DD_str  && DD_todc && DD_movR)
	{
		return 1; 
	}
	else
	{
		return -13;
	}
}

