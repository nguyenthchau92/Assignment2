/***********************************************************************
 * Module:  CASHIER.h
 * Author:  overflow
 * Modified: Saturday, February 16, 2019 2:43:17 PM
 * Purpose: Declaration of the class CASHIER
 ***********************************************************************/

#if !defined(__MOTOBIKESTOREMANAGEMENT_CASHIER_h)
#define __MOTOBIKESTOREMANAGEMENT_CASHIER_h

#pragma once
#include "afxwin.h"
#include "STAFF.h"

class BILL;
class STAFF;

class CASHIER : public STAFF
{
private:
   CString STA_STAFFID;
   CString BRANCHID;
   double DATEOFBIRTH;
   CString NAMESTAFF;
   bool SEX;
   CString ADDRESS;
   int SALARY;
   CString POSITION;
   
   BILL** beCreated;
   STAFF* sTAFF;

protected:
private:

};

#endif