#pragma once
#include "resource.h"
#include "DatabaseAppication.h"
#include "afxwin.h"
#include "STAFF.h"
#include "CUSTOMER.h"


// MotobikeInformationDlg dialog

class MotobikeInformationDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MotobikeInformationDlg)

public:
	MotobikeInformationDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~MotobikeInformationDlg();

// Dialog Data
	enum { IDD = IDD_DLG_LIST_MOTOBIKES_INFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
private:
	STAFF staffInfo;
	CUSTOMER customerInfo;
public:
	void setStaffInfor(STAFF staffInfo) { this->staffInfo = staffInfo; };
	void RoomHandler(CString nameroom);
	afx_msg void OnBnClickedCancel();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	void setBackground();
protected:
	CStatic picture_control_1;
	CBitmap cbitmap;
	HICON m_hIcon;
public:
	afx_msg void OnBnClickedBtnNextImage();
	afx_msg void OnBnClickedBtnPayment();
	afx_msg void OnBnClickedBtnBuy();
	void LoadUserNotPaid();
protected:
	CComboBox combo_userid;
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnMaintain();
};
