// InvoiceInformationDlg.cpp : implementation file
//

#include "stdafx.h"
#include <chrono>
#include "InvoiceInformationDlg.h"
#include "afxdialogex.h"
#include "DatabaseAppication.h"
#include "CUSTOMER.h"
#include "MOTOBIKE.h"
#include "SALER.h"
#include "BUYING.h"
#include "Util.h"
#include "BILL.h"

// InvoiceInformationDlg dialog

IMPLEMENT_DYNAMIC(InvoiceInformationDlg, CDialogEx)

InvoiceInformationDlg::InvoiceInformationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(InvoiceInformationDlg::IDD, pParent)
{

}

InvoiceInformationDlg::~InvoiceInformationDlg()
{
}

BOOL InvoiceInformationDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	list_ctrl_item.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	list_ctrl_item.InsertColumn(0, L"Name", LVCFMT_LEFT, 100);
	list_ctrl_item.InsertColumn(1, L"Year", LVCFMT_LEFT, 100);
	list_ctrl_item.InsertColumn(2, L"Price", LVCFMT_LEFT, 100);

	std::vector<MOTOBIKE> lstMotobike;
	std::vector<CString> motobikeData;
	// from motobikeID => year and price
	std::vector<CString> lstMotobikeId = bill.getLstMotobike();
	for (size_t i = 0; i < lstMotobikeId.size(); i++)
	{
		DatabaseAppication::getInstance()->ExeQuerySelectOneRowWithCond(L"MOTOBIKE", L"MOTOBIKEID=" + InsertSymbol2CString(lstMotobikeId[i]), motobikeData);
		MOTOBIKE temp;
		temp.setYEAR(CString2Int(motobikeData[4].Trim()));
		temp.setPRICE(CString2Int(motobikeData[7].Trim()));
		temp.setNAME(motobikeData[6]);
		lstMotobike.push_back(temp);
		motobikeData.clear();
	}
	
	// calulator Price
	float fCostInvoice = 0;
	for (int i = 0; i < lstMotobike.size(); i++)
	{
		MOTOBIKE tmp = lstMotobike[i];
		fCostInvoice += tmp.getPRICE();
	}	
	bill.setBILLPRICE((int)fCostInvoice);

	// update to GUI
	edit_name_user.SetWindowText(bill.getCUSTOMER().getCUSTOMERNAME());
	COleDateTime oleTime;
	oleTime.ParseDateTime(bill.getTimeInvoice());
	datetime_picker_invoice.SetTime(oleTime);
	edit_total_price.SetWindowText(Int2CString(bill.getBILLPRICE()));
	edit_staff_name.SetWindowText(bill.getSTAFF().getNAMESTAFF());

	// add name, year, price
	for (size_t i = 0; i < lstMotobike.size(); i++)
	{	
		list_ctrl_item.InsertItem(i, lstMotobike[i].getNAME());
		list_ctrl_item.SetItemText(i, 1, Int2CString(lstMotobike[i].getYEAR()));
		list_ctrl_item.SetItemText(i, 2, Int2CString(lstMotobike[i].getPRICE()));
	}

	UpdateData(false);

	return true;
}

void InvoiceInformationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NAME_USER, edit_name_user);
	DDX_Control(pDX, IDC_DATETIMEPICKER_INVOICE, datetime_picker_invoice);
	DDX_Control(pDX, IDC_EDIT_STAFF_NAME, edit_staff_name);
	DDX_Control(pDX, IDC_LIST_INVOICE_ITEMS, list_ctrl_item);
	DDX_Control(pDX, IDC_EDIT_TOTAL_PRICE, edit_total_price);
}


BEGIN_MESSAGE_MAP(InvoiceInformationDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &InvoiceInformationDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// InvoiceInformationDlg message handlers


void InvoiceInformationDlg::OnBnClickedOk()
{
	// update table invoice
	//TODO: random algorithm + create a serviceID by current time
	auto timeNow = std::chrono::system_clock::now();
	auto duration = timeNow.time_since_epoch();
	typedef std::chrono::duration<long double> MySecondTick;
	CString billID;
	billID.Format(L"%s%ld", L"service", duration.count());
	bill.setBILLID(billID);
	// update table BILL
	std::vector<CString> listData;
	listData.push_back(InsertSymbol2CString(bill.getBILLID()));
	listData.push_back(InsertSymbol2CString(bill.getCUSTOMER().getCUSTOMERID()));
	listData.push_back(InsertSymbol2CString(bill.getSTAFF().getSTAFFID()));
	listData.push_back(Int2CString(bill.getBILLPRICE()));
	listData.push_back(InsertSymbol2CString(bill.getTimeInvoice()));
	if (DatabaseAppication::getInstance()->ExecuteQueryInsert(L"BILL", listData) == false)
	{
		MessageBox(_T("use cashier account to excute payment"), _T("Info"), MB_OK | MB_ICONERROR);
		return;
	}
	//update table buying
	std::vector<CString> lstMotobikeId = bill.getLstMotobike();
	for (size_t i = 0; i < lstMotobikeId.size(); i++)
	{
		std::map<CString, CString> listReservationData;
		listReservationData[L"PAID"] = "1";
		std::map<CString, CString> listReserCondition;
		listReserCondition[L"MOTOBIKEID"] = InsertSymbol2CString(lstMotobikeId[i]);
		DatabaseAppication::getInstance()->ExecuteQueryUpdate(L"BUYING", listReservationData, listReserCondition);
	}
	// update data to gui
	UpdateData(false);
	CDialogEx::OnOK();
}
