
// ACManagementDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include <vector>


// MotobikeStoreManagementDlg dialog
class MotobikeStoreManagementDlg : public CDialogEx
{
// Construction
public:
	MotobikeStoreManagementDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MOTOBIKE_STORE_MANAGEMENT };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
public:


	void InitGUI();
	
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
protected:
	CEdit edit_username;
	CEdit edit_password;
public:
	afx_msg void OnBnClickedBtnLogin();
	afx_msg void OnBnClickedBtnRegister();
};
