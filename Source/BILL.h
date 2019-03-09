/***********************************************************************
 * Module:  BILL.h
 * Author:  overflow
 * Modified: Saturday, February 16, 2019 2:43:17 PM
 * Purpose: Declaration of the class BILL
 ***********************************************************************/

#if !defined(__MOTOBIKESTOREMANAGEMENT_BILL_h)
#define __MOTOBIKESTOREMANAGEMENT_BILL_h

#pragma once
#include "afxwin.h"

#include "CASHIER.h"
#include "CUSTOMER.h"
#include "STAFF.h"

class CUSTOMER;
class CASHIER;

class BILL
{
private:
   CString BILLID;
   int BILLPRICE;
   CString timeInvoice;
   std::vector<CString> lstMotobikeId;
   
   CUSTOMER customer;
   STAFF staff;

protected:
public:
	void setTimeInvoice(CString timeInvoice)
	{
		std::string sCheckoutDate = CStringA(timeInvoice.Trim());
		sCheckoutDate = sCheckoutDate.substr(0, sCheckoutDate.find_first_of(" "));
		this->timeInvoice = sCheckoutDate.c_str();
	}

	CString getTimeInvoice()
	{
		return this->timeInvoice;
	}

	void setLstMotobike(std::vector<CString> lstMotobikeId)
	{
		this->lstMotobikeId = lstMotobikeId;
	}

	std::vector<CString> getLstMotobike()
	{
		return this->lstMotobikeId;
	}

	void setSTAFF(STAFF STAFF)
	{
		this->staff = STAFF;
	}

	STAFF getSTAFF()
	{
		return this->staff;
	}

	void setCUSTOMER(CUSTOMER CUSTOMER)
	{
		this->customer = CUSTOMER;
	}

	CUSTOMER getCUSTOMER()
	{
		return this->customer;
	}

	void setBILLID(CString BILLID)
	{
		this->BILLID = BILLID;
	}

	CString getBILLID()
	{
		return this->BILLID;
	}

	void setBILLPRICE(int BILLPRICE)
	{
		this->BILLPRICE = BILLPRICE;
	}

	int getBILLPRICE()
	{
		return this->BILLPRICE;
	}





};

#endif