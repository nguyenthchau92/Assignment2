#pragma once
#include "afxwin.h"
#include "afxdtctl.h"
#include "MAINTAIN.h"
#include <vector>
#include <map>


// MaintainanceInformationDlg dialog

class MaintainanceInformationDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MaintainanceInformationDlg)

public:
	MaintainanceInformationDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~MaintainanceInformationDlg();
	BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_DLG_MAINTAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	CComboBox combo_mnt_userid;
	CEdit edit_mtn_cus_id;
	CDateTimeCtrl datetimepicker_mtn;
	CComboBox combo_mtn_staff_id;
	CEdit edit_information;
	MAINTAIN mtn;
	std::map<CString, CString> mapStaffIDStaffName;
	//std::map<CString, CString> mapMotobikeIDMotobikeName;
public:
	afx_msg void OnBnClickedOk();

	afx_msg void OnEditchangeComboUserID();
	afx_msg void OnEditchangeComboUserStaffID();
	afx_msg void OnEditchangeComboMotobikeID();
	afx_msg void OnEditupdateCombo2();
protected:
	CEdit combo_mtn_staff_name;
	CComboBox combo_mtn_motobike_id;
	CEdit combo_mtn_motobike_name;
	CString branchID;
	void setBranchID(CString branchID) { this->branchID = branchID; };
	CString getBranchID() { return branchID; };
	CEdit edit_mtn_cus_name;
	CEdit edit_mechanise_staff_name;
public:
	CEdit edit_mtn_motobike_name;
};
