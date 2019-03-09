#pragma once
#include "Resource.h"
#include "afxwin.h"
#include "afxdtctl.h"
#include "afxcmn.h"
#include <vector>

#include "STAFF.h"
#include "BILL.h"


// InvoiceInformationDlg dialog

class InvoiceInformationDlg : public CDialogEx
{
	DECLARE_DYNAMIC(InvoiceInformationDlg)

public:
	InvoiceInformationDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~InvoiceInformationDlg();
	virtual BOOL OnInitDialog();

	// Dialog Data
	enum { IDD = IDD_DIALOG_INVOICE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
private:
	BILL bill;

public:
	void setCustomerInfor(CUSTOMER customerInfo){ this->bill.setCUSTOMER(customerInfo); };
	void setStaffInfor(STAFF staffInformation){ this->bill.setSTAFF(staffInformation);};

	void setListMotobike(std::vector<CString> lstMotobikeId) { this->bill.setLstMotobike(lstMotobikeId); };
	
	void setTimeInvoice(CString timeInvoice) { this->bill.setTimeInvoice(timeInvoice); };
	void setBuildPrice(int billPrice) { this->bill.setBILLPRICE(billPrice); };

protected:
	CEdit edit_name_user;
public:
	CDateTimeCtrl datetime_picker_invoice;
protected:
	CEdit edit_staff_name;
	CListCtrl list_ctrl_item;
	CEdit edit_total_price;
};
