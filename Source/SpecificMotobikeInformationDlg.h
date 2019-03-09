#pragma once
#include "afxwin.h"
#include "resource.h"
#include "afxdtctl.h"
#include "afxcmn.h"
#include <vector>
#include <chrono>

#include "STAFF.h"
// SpecificMotobikeInformationDlg dialog

class SpecificMotobikeInformationDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SpecificMotobikeInformationDlg)

public:
	SpecificMotobikeInformationDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~SpecificMotobikeInformationDlg();
	virtual BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG_SPECIFIC_MOTOBIKE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
protected:
	CEdit edit_name_customer;
	CEdit edit_id_customer;
	CDateTimeCtrl datetime_checkin_room;
	CDateTimeCtrl datetime_checkout_room;
	bool isRented;
	CComboBox combox_sex;
	CEdit edit_age;
	CEdit edit_address;
	CString roomID;
	STAFF staffInfo;
	CString serviceID;
	CString g_customerID;
	CString g_checkinDate;
	CString g_checkoutdate;
	std::vector<CString> lstFood;
public:
	static int counterService;
public:
	afx_msg void OnBnClickedOk();
public: 
	void setRoomID(CString roomID) { this->roomID = roomID; };
	void setStaffInfo(STAFF staffInfo) { this->staffInfo = staffInfo; };
	void setIsRented(bool isRented) { this->isRented = isRented; };
public:
	afx_msg void OnBnClickedButtonPayment();
protected:
	CComboBox combo_type;
	CComboBox combo_producer;
	CComboBox combo_year;
	CComboBox combo_color;
};
