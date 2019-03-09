/***********************************************************************
 * Module:  STAFF.h
 * Author:  overflow
 * Modified: Saturday, February 16, 2019 2:43:17 PM
 * Purpose: Declaration of the class STAFF
 ***********************************************************************/

#if !defined(__MOTOBIKESTOREMANAGEMENT_STAFF_h)
#define __MOTOBIKESTOREMANAGEMENT_STAFF_h

#pragma once
#include "afxwin.h"

class REGISTER;
class SALER;
class MECHANISE;
class CASHIER;
class BRANCH;

class STAFF
{
private:
   CString STAFFID;
   double DATEOFBIRTH;
   CString NAMESTAFF;
   bool SEX;
   CString ADDRESS;
   int SALARY;
   CString POSITION;
   CString branchID;
   
   STAFF** sTAFFB;
   REGISTER* rEGISTER;
   SALER** sALER;
   MECHANISE** mECHANISE;
   CASHIER** cASHIER;
   STAFF* sTAFFA;
   BRANCH* beWork;

protected:
public:
	void setBranchID(CString branchID)
	{
		this->branchID = branchID;
	}

	CString getBranchID()
	{
		return this->branchID;
	}

	void setSTAFFID(CString STAFFID)
	{
		this->STAFFID = STAFFID;
	}

	CString getSTAFFID()
	{
		return this->STAFFID;
	}

	void setNAMESTAFF(CString NAMESTAFF)
	{
		this->NAMESTAFF = NAMESTAFF;
	}

	CString getNAMESTAFF()
	{
		return this->NAMESTAFF;
	}

	void setSALARY(int SALARY)
	{
		this->SALARY = SALARY;
	}

	int getSALARY()
	{
		return this->SALARY;
	}

};

#endif