/***********************************************************************
 * Module:  CUSTOMER.h
 * Author:  overflow
 * Modified: Saturday, February 16, 2019 2:43:17 PM
 * Purpose: Declaration of the class CUSTOMER
 ***********************************************************************/

#if !defined(__MOTOBIKESTOREMANAGEMENT_CUSTOMER_h)
#define __MOTOBIKESTOREMANAGEMENT_CUSTOMER_h

#pragma once
#include "afxwin.h"

class BILL;
class BUYING;
class MAINTAIN;

class CUSTOMER
{
private:
	CString CUSTOMERID;
	CString CUSTOMERNAME;
	CString CUSTOMERADDRESS;
	int CUSTOMERAGE;
	bool CUSTOMERSEX;

	BILL** bePaid;
	BUYING** bUYING;
	MAINTAIN** mAINTAIN;

protected:
public:
	CUSTOMER()
	{
		CUSTOMERSEX = false;
	}

	void setCUSTOMERID(CString CUSTOMERID)
	{
		this->CUSTOMERID = CUSTOMERID;
	}

	void setCUSTOMERADDRESS(CString CUSTOMERADDRESS)
	{
		this->CUSTOMERADDRESS = CUSTOMERADDRESS;
	}

	void setCUSTOMERNAME(CString CUSTOMERNAME)
	{
		this->CUSTOMERNAME = CUSTOMERNAME;
	}

	void setCUSTOMERAGE(int CUSTOMERAGE)
	{
		this->CUSTOMERAGE = CUSTOMERAGE;
	}

	void setCUSTOMERSEX(bool CUSTOMERSEX)
	{
		this->CUSTOMERSEX = CUSTOMERSEX;
	}

	CString getCUSTOMERADDRESS()
	{
		return CUSTOMERADDRESS;
	}

	CString getCUSTOMERID()
	{
		return CUSTOMERID;
	}

	CString getCUSTOMERNAME()
	{
		return CUSTOMERNAME;
	}

	int getCUSTOMERAGE()
	{
		return CUSTOMERAGE;
	}

	bool getCUSTOMERSEX()
	{
		return CUSTOMERSEX;
	}
};

#endif