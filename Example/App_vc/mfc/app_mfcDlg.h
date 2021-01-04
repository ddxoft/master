
// app_mfcDlg.h : 头文件
//

#pragma once
#include "DD.h"

// Capp_mfcDlg 对话框
class Capp_mfcDlg : public CDialog
{
// 构造
public:
	Capp_mfcDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_APP_MFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonfindfile();
	afx_msg void OnBnClickedButtontest();
	afx_msg void OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();

public:
	void SetStatus(int val);
	void SetHotKey(void);
	void UnHotKey(void);
	CString LoadFromReg();
	CString m_dllfile;
	int m_sel;
	CDD dd ;  // DD 类
};
