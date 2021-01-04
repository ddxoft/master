
// app_mfcDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "app_mfc.h"
#include "app_mfcDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Capp_mfcDlg 对话框
Capp_mfcDlg::Capp_mfcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(Capp_mfcDlg::IDD, pParent)
	, m_sel(0)
	, m_dllfile(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Capp_mfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_sel);
	DDX_Text(pDX, IDC_EDIT_dllfile, m_dllfile);
}

BEGIN_MESSAGE_MAP(Capp_mfcDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_findfile, &Capp_mfcDlg::OnBnClickedButtonfindfile)
	ON_BN_CLICKED(IDC_BUTTON_test, &Capp_mfcDlg::OnBnClickedButtontest)
	ON_WM_HOTKEY()
	ON_WM_TIMER()
	ON_WM_CLOSE()
//	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// Capp_mfcDlg 消息处理程序

BOOL Capp_mfcDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);		
	SetIcon(m_hIcon, FALSE);	
	
	SetHotKey();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Capp_mfcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR Capp_mfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Capp_mfcDlg::OnBnClickedButtonfindfile()
{
	LPCWSTR filter = L"DD dll|*.dll";
	CFileDialog 	dlg(TRUE,L"DD",L"", OFN_HIDEREADONLY  , filter ,NULL,0,TRUE);

	WCHAR fileBuffer[MAX_PATH] = {0};
	dlg.m_ofn.lpstrFile = fileBuffer;
	dlg.m_ofn.nMaxFile= MAX_PATH;

	if (  dlg.DoModal() == IDOK)
	{
		m_dllfile = dlg.GetPathName();
		UpdateData(FALSE);

		int ret = dd.GetFunAddr(m_dllfile) ;
		
		SetStatus(ret);
	}
}

void Capp_mfcDlg::OnBnClickedButtontest()
{
	CString s;
	GetDlgItem(IDC_BUTTON_test)->GetWindowText(s);

	if ( s== L"Start")
	{
		GetDlgItem(IDC_BUTTON_test)->SetWindowText(L"Stop");
		SetTimer(0,3000,0);
	}
	else
	{
		GetDlgItem(IDC_BUTTON_test)->SetWindowText(L"Start");
		KillTimer(0);
	}
}


void Capp_mfcDlg::SetStatus(int val)
{
	GetDlgItem(IDC_BUTTON_test)->EnableWindow(false);

	switch(val)
	{
	case 1:
		{
			int st = dd.DD_btn(0);
			if (st == 1)
			{
				AfxMessageBox(L"DD Load OK");				
				GetDlgItem(IDC_BUTTON_test)->EnableWindow(true);
			}
			else
			{
				AfxMessageBox(L"DD Initialize Error");				
			}
		}
		break;
	case -1:
	case -2:
	case -3:
		AfxMessageBox(L"DD Load Error");
		break;
	default:
		AfxMessageBox(L"Error");
		break;
	}

}


void Capp_mfcDlg::SetHotKey(void)
{
	::RegisterHotKey(GetSafeHwnd(),6688, 0   ,  VK_F8); 
	::RegisterHotKey(GetSafeHwnd(),6689, 0   ,  VK_F9); 

}
void Capp_mfcDlg::UnHotKey(void)
{
	::UnregisterHotKey(GetSafeHwnd() ,6688);	
	::UnregisterHotKey(GetSafeHwnd() ,6689);
}



void Capp_mfcDlg::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	switch (nHotKeyId)
	{
	case 6688:  
		// ctrl+alt+del
		dd.DD_key( 600  ,  1);  //600 == L.CTRL down
		dd.DD_key( 602  ,  1);  //602 == L.ALT   down
		dd.DD_key( 706  ,  1);  //706 == DEL   down
		dd.DD_key( 706  ,  2);  
		dd.DD_key( 602  ,  2); 	 //up
		dd.DD_key( 600  ,  2);         
     	break;
	case  6689:  
		// type visiable char
		dd.DD_str("Keyboard char [A-Za_z] {@$} ");
		break;
	default:
		break;
	}

	CDialog::OnHotKey(nHotKeyId, nKey1, nKey2);
}

void Capp_mfcDlg::OnTimer(UINT_PTR nIDEvent)
{
	UpdateData(TRUE);
				
	switch(m_sel+1)
	{
	case 1 :                     
		//1==L.down, 2==L.up, 4==R.down, 8==R.up, 16==M.down, 32==M.up
		dd.DD_btn(1);  
		Sleep(50); //may, delay 50ms
		dd.DD_btn(2);
		break;
	case 2 :                    
		dd.DD_movR(20, 20);   //move rel.
		dd.DD_mov(200, 200); //move abs.
		break;
	case 3 :
		dd.DD_whl(1);		//up
		Sleep(200);
		dd.DD_whl(2);       //down
		break;
	case 4 :                   
		{                                             
			int ddcode=300;		//tab == 300 in ddcode	   
			ddcode = dd.DD_todc(VK_TAB);
			dd.DD_key( ddcode ,1); 
			Sleep(1);					//may, delay 50ms
			dd.DD_key( ddcode ,2);
		}
		break;
	}
	CDialog::OnTimer(nIDEvent);
}

void Capp_mfcDlg::OnClose()
{
	UnHotKey();
	KillTimer(0);
	CDialog::OnClose();
}


