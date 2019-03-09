// SpecificMotobikeInformationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SpecificMotobikeInformationDlg.h"
#include "afxdialogex.h"
#include "DatabaseAppication.h"
#include "InvoiceInformationDlg.h"
#include "Util.h"
#include "CUSTOMER.h"
#include "MOTOBIKE.h"
#include "BUYING.h"

// SpecificMotobikeInformationDlg dialog

IMPLEMENT_DYNAMIC(SpecificMotobikeInformationDlg, CDialogEx)
int SpecificMotobikeInformationDlg::counterService = 0;

BOOL SpecificMotobikeInformationDlg::OnInitDialog()
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

	combox_sex.AddString(L"Female");
	combox_sex.AddString(L"Male");
	combox_sex.SetCurSel(1);

	// create data for motobike information
	// add type motobike
	std::vector<CString> lstTypeMotobike;
	DatabaseAppication::getInstance()->ExecuteQueryDistinctSelect(L"MOTOBIKE", L"MOTOBIKETYPE", lstTypeMotobike);
	for (size_t i = 0; i < lstTypeMotobike.size(); i++)
	{
		combo_type.AddString(lstTypeMotobike[i]);
	}
	combo_type.SetCurSel(0);
	// add producer motobike
	std::vector<CString> lstProducerMotobike;
	DatabaseAppication::getInstance()->ExecuteQueryDistinctSelect(L"MOTOBIKE", L"PRODUCER", lstProducerMotobike);
	for (size_t i = 0; i < lstProducerMotobike.size(); i++)
	{
		combo_producer.AddString(lstProducerMotobike[i]);
	}
	combo_producer.SetCurSel(0);
	// add year motobike
	std::vector<CString> lstYearMotobike;
	DatabaseAppication::getInstance()->ExecuteQueryDistinctSelect(L"MOTOBIKE", L"YEAR", lstYearMotobike);
	for (size_t i = 0; i < lstYearMotobike.size(); i++)
	{
		combo_year.AddString(lstYearMotobike[i]);
	}
	combo_year.SetCurSel(0);
	// add color motobike
	std::vector<CString> lstColorMotobike;
	DatabaseAppication::getInstance()->ExecuteQueryDistinctSelect(L"MOTOBIKE", L"MOTOBIKECOLOR", lstColorMotobike);
	for (size_t i = 0; i < lstColorMotobike.size(); i++)
	{
		combo_color.AddString(lstColorMotobike[i]);
	}
	combo_color.SetCurSel(0);

	// update data to gui
	UpdateData(false);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

SpecificMotobikeInformationDlg::SpecificMotobikeInformationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(SpecificMotobikeInformationDlg::IDD, pParent)
{
}

SpecificMotobikeInformationDlg::~SpecificMotobikeInformationDlg()
{
}

void SpecificMotobikeInformationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NAME_CUSTOMER, edit_name_customer);
	DDX_Control(pDX, IDC_EDIT_ID_CUSTOMER, edit_id_customer);
	DDX_Control(pDX, IDC_DATETIMEPICKER_IN, datetime_checkin_room);
	DDX_Control(pDX, IDC_COMBO_SEX, combox_sex);
	DDX_Control(pDX, IDC_EDIT_AGE, edit_age);
	DDX_Control(pDX, IDC_EDIT_ADDRESS, edit_address);
	DDX_Control(pDX, IDC_COMBO_TYPE, combo_type);
	DDX_Control(pDX, IDC_COMBO_PRODUCER, combo_producer);
	DDX_Control(pDX, IDC_COMBO_YEAR, combo_year);
	DDX_Control(pDX, IDC_COMBO_COLOR, combo_color);
}


BEGIN_MESSAGE_MAP(SpecificMotobikeInformationDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &SpecificMotobikeInformationDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_PAYMENT, &SpecificMotobikeInformationDlg::OnBnClickedButtonPayment)
END_MESSAGE_MAP()


// SpecificMotobikeInformationDlg message handlers

void SpecificMotobikeInformationDlg::OnBnClickedOk()
{
	// get user information
	CUSTOMER customer;
	CString name, identification, age, address, sex;
	edit_name_customer.GetWindowText(name);
	edit_id_customer.GetWindowText(identification);
	combox_sex.GetLBText(combox_sex.GetCurSel(), sex);
	edit_age.GetWindowText(age);
	edit_address.GetWindowText(address);

	customer.setCUSTOMERNAME(name);
	customer.setCUSTOMERID(identification);
	if (sex == L"Male")
		customer.setCUSTOMERSEX(true);
	else
		customer.setCUSTOMERSEX(false);
	customer.setCUSTOMERADDRESS(address);
	customer.setCUSTOMERAGE(_wtoi(age));
	// Get information from graphic application
	std::vector<CString> customerData;
	CString conditionCus = L"CUSTOMERID=" + InsertSymbol2CString(customer.getCUSTOMERID());
	DatabaseAppication::getInstance()->ExeQuerySelectOneRowWithCond(L"CUSTOMER", conditionCus, customerData);
	if (customerData.size() > 0)
	{
		std::map<CString, CString> listData, listCondition;
		listData[L"CUSTOMERAGE"] = Int2CString(customer.getCUSTOMERAGE());
		listData[L"CUSTOMERADDRESS"] = InsertSymbol2CString(customer.getCUSTOMERADDRESS());
		listCondition[L"CUSTOMERID"] = InsertSymbol2CString(customer.getCUSTOMERID());
		DatabaseAppication::getInstance()->ExecuteQueryUpdate(L"CUSTOMER", listData, listCondition);
	}
	else
	{
		std::vector<CString> lstUserField;
		lstUserField.push_back(InsertSymbol2CString(customer.getCUSTOMERID()));
		lstUserField.push_back(InsertSymbol2CString(customer.getCUSTOMERNAME()));
		lstUserField.push_back(Int2CString(customer.getCUSTOMERAGE()));
		lstUserField.push_back(Int2CString(customer.getCUSTOMERSEX()));
		lstUserField.push_back(InsertSymbol2CString(customer.getCUSTOMERADDRESS()));
		DatabaseAppication::getInstance()->ExecuteQueryInsert(L"CUSTOMER", lstUserField);
	}

	// get motobike information
	MOTOBIKE motobike;
	CString type, producer, year, color;
	combo_type.GetLBText(combo_type.GetCurSel(), type);
	combo_producer.GetLBText(combo_producer.GetCurSel(), producer);
	combo_year.GetLBText(combo_year.GetCurSel(), year);
	combo_color.GetLBText(combo_color.GetCurSel(), color);

	motobike.setMOTOBIKETYPE(type);
	motobike.setPRODUCER(producer);
	motobike.setYEAR(_tstof(year));
	motobike.setMOTOBIKECOLOR(color);
	// update database
	BUYING trade;
	CString buyDate;
	CTime cBuyDate;
	datetime_checkin_room.GetTime(cBuyDate);
	cBuyDate.GetDay();
	buyDate.Format(L"%d-%d-%d", cBuyDate.GetYear(), cBuyDate.GetMonth(), cBuyDate.GetDay());
	// Motobike
	std::vector<CString> motobikeData;
	std::vector<CString> condition;
	CString condition1 = L"MOTOBIKETYPE=" + InsertSymbol2CString(motobike.getMOTOBIKETYPE());
	CString condition2 = L"PRODUCER=" + InsertSymbol2CString(motobike.getPRODUCER());
	CString condition3 = L"YEAR=" + Int2CString(motobike.getYEAR());
	CString condition4 = L"MOTOBIKECOLOR=" + InsertSymbol2CString(motobike.getMOTOBIKECOLOR());
	CString condition5 = L"STATUS=0";
	condition.push_back(condition1);
	condition.push_back(condition2);
	condition.push_back(condition3);
	condition.push_back(condition4);
	condition.push_back(condition5);
	DatabaseAppication::getInstance()->ExeQuerySelectWithMultipleCond(L"MOTOBIKE", condition, motobikeData);
	if (motobikeData.size() <= 0)
	{
		MessageBox(_T("Your motobike does not exist in our database"), _T("Infor"), MB_OK | MB_ICONERROR);
		return;
	}

	motobike.setMOTOBIKEID(motobikeData[0]);
	std::map<CString, CString> listData, listCondition;
	listData[L"STATUS"] = L"1";
	listCondition[L"MOTOBIKEID"] = InsertSymbol2CString(motobike.getMOTOBIKEID());
	if (DatabaseAppication::getInstance()->ExecuteQueryUpdate(L"MOTOBIKE", listData, listCondition) == false)
	{
		MessageBox(_T("Just user seller can sell motobike"), _T("Info"), MB_OK | MB_ICONERROR);
		return;
	}
	// Buying
	BUYING buying;
	buying.setBUYDATE(buyDate);
	buying.setCUSTOMER(customer);
	buying.setMOTOBIKE(motobike);
	buying.setPAID(false);
	SALER saler;
	saler.setSTAFFID(staffInfo.getSTAFFID());
	// Customer
	std::vector<CString> lstBuyingField;
	lstBuyingField.push_back(InsertSymbol2CString(saler.getSTAFFID()));
	lstBuyingField.push_back(InsertSymbol2CString(customer.getCUSTOMERID()));
	lstBuyingField.push_back(InsertSymbol2CString(buying.getMOTOBIKE().getMOTOBIKEID()));
	lstBuyingField.push_back(InsertSymbol2CString(buying.getBUYDATE()));
	lstBuyingField.push_back(L"0");
	// Update information to database
	bool ret = DatabaseAppication::getInstance()->ExecuteQueryInsert(L"BUYING", lstBuyingField);
	if (ret == false)
	{
		MessageBox(_T("Just user seller can sell motobike"), _T("Info"), MB_OK | MB_ICONERROR);
	}
	CDialogEx::OnOK();
}

void SpecificMotobikeInformationDlg::OnBnClickedButtonPayment()
{

}
