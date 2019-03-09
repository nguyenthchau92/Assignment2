// MaintainanceInformationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MotobikeStoreManagement.h"
#include "MaintainanceInformationDlg.h"
#include "afxdialogex.h"
#include "Util.h"
#include "DatabaseAppication.h"
#include <chrono>

// MaintainanceInformationDlg dialog


IMPLEMENT_DYNAMIC(MaintainanceInformationDlg, CDialogEx)

MaintainanceInformationDlg::MaintainanceInformationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MaintainanceInformationDlg::IDD, pParent)
{

}

MaintainanceInformationDlg::~MaintainanceInformationDlg()
{
}

BOOL MaintainanceInformationDlg::OnInitDialog()
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

	// update data to comboxbox based on customer id
	// select user ID, Name from branch Database
	std::vector<std::vector<CString>> lstData;
	DatabaseAppication::getInstance()->ExecuteQueryDistinctSelectWithCondition(L"BUYING", L"CUSTOMERID", L"PAID=1", lstData);
	for (size_t i = 0; i < lstData.size(); i++)
	{
		std::vector<CString> tmp = lstData[i];
		CString CUSTOMERID = tmp[0].Trim();
		if (combo_mnt_userid.FindString(0, CUSTOMERID) == -1)
			combo_mnt_userid.AddString(CUSTOMERID);
	}
	combo_mnt_userid.SetCurSel(0);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void MaintainanceInformationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_MTN_USERID, combo_mnt_userid);
	DDX_Control(pDX, IDC_EDIT_MTN_CUS_NAME, edit_mtn_cus_name);
	DDX_Control(pDX, IDC_DATETIMEPICKER_MTN, datetimepicker_mtn);
	DDX_Control(pDX, IDC_COMBO_MTN_STAFF_ID, combo_mtn_staff_id);
	DDX_Control(pDX, IDC_EDIT_MECHANISE_STAFF_NAME, edit_mechanise_staff_name);
	DDX_Control(pDX, IDC_COMBO_MTN_MOTOBIKE_ID, combo_mtn_motobike_id);
	DDX_Control(pDX, IDC_EDIT_MTN_MOTOBIKE_NAME, edit_mtn_motobike_name);
	DDX_Control(pDX, IDC_EDIT_INFORMATION, edit_information);
}


BEGIN_MESSAGE_MAP(MaintainanceInformationDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &MaintainanceInformationDlg::OnBnClickedOk)
	ON_CBN_SELENDOK(IDC_COMBO_MTN_USERID, &MaintainanceInformationDlg::OnEditchangeComboUserID)
	ON_CBN_SELENDOK(IDC_COMBO_MTN_STAFF_ID, &MaintainanceInformationDlg::OnEditchangeComboUserStaffID)
	ON_CBN_SELENDOK(IDC_COMBO_MTN_MOTOBIKE_ID, &MaintainanceInformationDlg::OnEditchangeComboMotobikeID)
	ON_CBN_EDITUPDATE(IDC_COMBO_MTN_USERID, &MaintainanceInformationDlg::OnEditupdateCombo2)
END_MESSAGE_MAP()


// MaintainanceInformationDlg message handlers
void MaintainanceInformationDlg::OnEditchangeComboMotobikeID()
{
	// get motobikeID
	CString motobikeID;
	combo_mtn_motobike_id.GetLBText(combo_mtn_motobike_id.GetCurSel(), motobikeID);
	// motobike id => motobike name
	std::vector<CString> motobikeData;
	// from motobikeID => year and price
	DatabaseAppication::getInstance()->ExeQuerySelectOneRowWithCond(L"MOTOBIKE", L"MOTOBIKEID=" + InsertSymbol2CString(motobikeID.Trim()), motobikeData);
	edit_mtn_motobike_name.SetWindowText(motobikeData[6].Trim());
}

void MaintainanceInformationDlg::OnEditchangeComboUserStaffID()
{
	// get staffID
	CString staffID;
	combo_mtn_staff_id.GetLBText(combo_mtn_staff_id.GetCurSel(), staffID);
	edit_mechanise_staff_name.SetWindowText(mapStaffIDStaffName[staffID]);
}

void MaintainanceInformationDlg::OnEditchangeComboUserID()
{
	// Get information from graphic application
	CString customerId;
	combo_mnt_userid.GetLBText(combo_mnt_userid.GetCurSel(), customerId);
	// customer id-> customer name
	std::vector<CString> customerData;
	CString conditionCus = L"CUSTOMERID=" + InsertSymbol2CString(customerId);
	DatabaseAppication::getInstance()->ExeQuerySelectOneRowWithCond(L"CUSTOMER", conditionCus, customerData);
	edit_mtn_cus_name.SetWindowText(customerData[1].Trim());
	// get mechanise id, merchanise name
	std::vector<std::vector<CString>> lstMechanise;
	combo_mtn_staff_id.ResetContent();
	DatabaseAppication::getInstance()->ExecuteQuerySelect(L"MECHANISE", lstMechanise);
	for (size_t i = 0; i < lstMechanise.size(); i++)
	{
		std::vector<CString> tmp = lstMechanise[i];
		combo_mtn_staff_id.AddString(tmp[0].Trim());
		mapStaffIDStaffName[tmp[0].Trim()] = tmp[4].Trim();
	}
	// get list motobike id
	std::vector<CString> lstMotobikeId;
	std::vector<std::vector<CString>> buyingData;
	combo_mtn_motobike_id.ResetContent();
	std::vector<CString> condition;
	CString condition1 = L"CUSTOMERID=" + InsertSymbol2CString(customerId);
	CString condition2 = L"PAID=1";
	condition.push_back(condition1);
	condition.push_back(condition2);
	DatabaseAppication::getInstance()->ExeQuerySelecMultipleRowtWithMultipleCond(L"BUYING", condition, buyingData);
	for (size_t i = 0; i < buyingData.size(); i++)
	{
		std::vector<CString> tmp = buyingData[i];
		combo_mtn_motobike_id.AddString(tmp[2]);
	}
}

void MaintainanceInformationDlg::OnEditupdateCombo2()
{
	int x = 0;
	int y = x + 1;

}

void MaintainanceInformationDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//TODO: random algorithm + create a serviceID by current time
	auto timeNow = std::chrono::system_clock::now();
	auto duration = timeNow.time_since_epoch();
	typedef std::chrono::duration<long double> MySecondTick;
	CString serviceID;
	serviceID.Format(L"%s%ld", L"serviceID", duration.count());

	// get staffID
	CString staffID;
	combo_mtn_staff_id.GetLBText(combo_mtn_staff_id.GetCurSel(), staffID);
	// get customerID
	CString customerID;
	combo_mnt_userid.GetLBText(combo_mnt_userid.GetCurSel(), customerID);
	// get motobikeID
	CString motobikeID;
	combo_mtn_motobike_id.GetLBText(combo_mtn_motobike_id.GetCurSel(), motobikeID);

	// get time from gui
	CString maintainDate;
	CTime cBuyMtnDate;
	datetimepicker_mtn.GetTime(cBuyMtnDate);
	cBuyMtnDate.GetDay();
	maintainDate.Format(L"%d-%d-%d", cBuyMtnDate.GetYear(), cBuyMtnDate.GetMonth(), cBuyMtnDate.GetDay());

	// get information
	CString information;
	edit_information.GetWindowText(information);
	std::vector<CString> listData;
	listData.push_back(InsertSymbol2CString(staffID));
	listData.push_back(InsertSymbol2CString(serviceID));
	listData.push_back(InsertSymbol2CString(motobikeID));
	listData.push_back(InsertSymbol2CString(maintainDate));
	listData.push_back(InsertSymbol2CString(information));
	// update to database
	std::vector<CString> listServiceData;
	listServiceData.push_back(InsertSymbol2CString(serviceID));
	listServiceData.push_back(InsertSymbol2CString(customerID));
	DatabaseAppication::getInstance()->ExecuteQueryInsert(L"SERVICE", listServiceData);
	DatabaseAppication::getInstance()->ExecuteQueryInsert(L"MAINTAIN", listData);

	CDialogEx::OnOK();
}
