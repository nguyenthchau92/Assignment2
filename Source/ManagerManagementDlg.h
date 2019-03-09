#pragma once
#include "Resource.h"
#include "afxwin.h"
#include "afxcmn.h"
#include "STAFF.h"


// ManagerManagementDlg dialog

class ManagerManagementDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ManagerManagementDlg)

public:
	ManagerManagementDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~ManagerManagementDlg();
	virtual BOOL OnInitDialog();

	// Dialog Data
	enum { IDD = IDD_MANAGER_MANAGEMENT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	CComboBox combo_month;
	CComboBox combo_year;
	STAFF staffInformation;
	CString branchID;
	float fTotalIncome;
public:
	CListCtrl lst_ctrl_invoice;
protected:
	CListCtrl lst_ctrl_salary;
	CEdit edit_total_income;
public:
	afx_msg void OnBnClickedBtnCalculate();
	void setStaffInformation(STAFF staffInformation) { this->staffInformation = staffInformation; };
	void setBranchID(CString branchID) { this->branchID = branchID; };
	afx_msg void OnBnClickedBtnRoomMng();
	afx_msg void OnBnClickedOk();
};
