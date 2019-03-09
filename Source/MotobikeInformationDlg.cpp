// MotobikeInformationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MotobikeInformationDlg.h"
#include "afxdialogex.h"
#include "SpecificMotobikeInformationDlg.h"
#include "InvoiceInformationDlg.h"
#include "MaintainanceInformationDlg.h"
#include <map>


// MotobikeInformationDlg dialog

IMPLEMENT_DYNAMIC(MotobikeInformationDlg, CDialogEx)

MotobikeInformationDlg::MotobikeInformationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MotobikeInformationDlg::IDD, pParent)
{

}

MotobikeInformationDlg::~MotobikeInformationDlg()
{
}

void MotobikeInformationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICTURE_CONTROL_1, picture_control_1);
	DDX_Control(pDX, IDC_COMBO_USERID, combo_userid);
}


BEGIN_MESSAGE_MAP(MotobikeInformationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &MotobikeInformationDlg::OnBnClickedCancel)
	ON_WM_DRAWITEM()
	ON_BN_CLICKED(IDC_BTN_NEXT_IMAGE, &MotobikeInformationDlg::OnBnClickedBtnNextImage)
	ON_BN_CLICKED(IDC_BTN_PAYMENT, &MotobikeInformationDlg::OnBnClickedBtnPayment)
	ON_BN_CLICKED(IDC_BTN_BUY, &MotobikeInformationDlg::OnBnClickedBtnBuy)
	ON_BN_CLICKED(IDOK, &MotobikeInformationDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BTN_MAINTAIN, &MotobikeInformationDlg::OnBnClickedBtnMaintain)
END_MESSAGE_MAP()


// MotobikeInformationDlg message handlers

void MotobikeInformationDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void MotobikeInformationDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CDialog::OnDrawItem(nIDCtl, lpDrawItemStruct);
}

BOOL MotobikeInformationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	cbitmap.LoadBitmap(IDB_BITMAP1);
	picture_control_1.SetBitmap((HBITMAP)cbitmap.Detach());

	// init data in user_combo_box
	LoadUserNotPaid();

	return TRUE;  // return TRUE  unless you set the focus to a control
}


void MotobikeInformationDlg::OnBnClickedBtnNextImage()
{
	static int counter = 0;
	if (counter == 0)
		cbitmap.LoadBitmap(IDB_BITMAP1);
	if (counter == 1)
		cbitmap.LoadBitmap(IDB_BITMAP2);
	if (counter == 2)
		cbitmap.LoadBitmap(IDB_BITMAP3);
	
	picture_control_1.SetBitmap((HBITMAP)cbitmap.Detach());
	counter++;
	if (counter == 3)
		counter = 0;
	UpdateData(false);
}

void MotobikeInformationDlg::OnBnClickedBtnPayment()
{
	// get customerID from combobox
	CString customer_id;
	CString buydingDate;
	combo_userid.GetLBText(combo_userid.GetCurSel(), customer_id);
	// get list motobike id
	std::vector<CString> lstMotobikeId;
	std::vector<std::vector<CString>> buyingData;
	std::vector<CString> condition;
	CString condition1 = L"CUSTOMERID=" + InsertSymbol2CString(customer_id);
	CString condition2 = L"PAID=0";
	condition.push_back(condition1);
	condition.push_back(condition2);
	DatabaseAppication::getInstance()->ExeQuerySelecMultipleRowtWithMultipleCond(L"BUYING", condition, buyingData);
	for (size_t i = 0; i < buyingData.size(); i++)
	{
		std::vector<CString> tmp = buyingData[i];
		lstMotobikeId.push_back(tmp[2].Trim());
		// get buying when i = 0
		if (i == 0)
			buydingDate = tmp[3].Trim();
	}

	// Get customer information from customer table
	std::vector<CString> userInfo;
	CString condition3 = L"CUSTOMERID=" + InsertSymbol2CString(customer_id);
	DatabaseAppication::getInstance()->ExeQuerySelectOneRowWithCond(L"CUSTOMER", condition3, userInfo);
	customerInfo.setCUSTOMERID(customer_id.Trim());
	customerInfo.setCUSTOMERNAME(userInfo[1].Trim());
	
	InvoiceInformationDlg invoice;
	invoice.setCustomerInfor(customerInfo);
	invoice.setStaffInfor(staffInfo);
	invoice.setListMotobike(lstMotobikeId);
	invoice.setTimeInvoice(buydingDate);
	int errorCode = invoice.DoModal();
	switch (errorCode)
	{
	case IDOK:
		// reload gui
		LoadUserNotPaid();
		break;
	case IDCANCEL:
	case IDCLOSE:
		break;
	default:
		break;
	}
}


void MotobikeInformationDlg::OnBnClickedBtnBuy()
{
	// TODO: Add your control notification handler code here
	SpecificMotobikeInformationDlg motobikeDlg;
	motobikeDlg.setStaffInfo(staffInfo);
	motobikeDlg.DoModal();
	// reload gui
	LoadUserNotPaid();
}

void MotobikeInformationDlg::LoadUserNotPaid()
{
	combo_userid.ResetContent();
	// init data in user_combo_box
	std::vector<CString> lstMotobikeId;
	std::vector<std::vector<CString>> customerData;
	std::vector<CString> condition;
	CString condition1 = L"BRANCHID=" + InsertSymbol2CString(staffInfo.getBranchID());
	condition.push_back(condition1);
	DatabaseAppication::getInstance()->ExeQuerySelecMultipleRowtWithMultipleCond(L"STAFF", condition, customerData);
	
	std::vector<std::vector<CString>> lstData;
	DatabaseAppication::getInstance()->ExecuteQueryDistinctSelectWithCondition(L"BUYING", L"STAFFID, CUSTOMERID", L"PAID=0", lstData);
	for (size_t i = 0; i < lstData.size(); i++)
	{
		std::vector<CString> tmp = lstData[i];
		CString STAFFID = tmp[0].Trim();
		CString CUSTOMERID = tmp[1].Trim();
		for (size_t i = 0; i < customerData.size(); i++)
		{
			std::vector<CString> tmp2 = customerData[i];
			if (tmp2[0].Trim().Compare(STAFFID) == 0)
				combo_userid.AddString(CUSTOMERID);
		}
	}
}


void MotobikeInformationDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void MotobikeInformationDlg::OnBnClickedBtnMaintain()
{
	// TODO: Add your control notification handler code here
	MaintainanceInformationDlg dlg;
	dlg.DoModal();

}
