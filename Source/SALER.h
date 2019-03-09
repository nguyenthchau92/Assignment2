/***********************************************************************
 * Module:  SALER.h
 * Author:  overflow
 * Modified: Saturday, February 16, 2019 2:43:17 PM
 * Purpose: Declaration of the class SALER
 ***********************************************************************/

#if !defined(__MOTOBIKESTOREMANAGEMENT_SALER_h)
#define __MOTOBIKESTOREMANAGEMENT_SALER_h

#pragma once
#include "afxwin.h"
#include "STAFF.h"

//class BUYING;
//class STAFF;

class SALER : public STAFF
{
private:
   CString STAFFID;
   CString BRANCHID;
   double DATEOFBIRTH;
   CString NAMESTAFF;
   bool SEX;
   CString ADDRESS;
   int SALARY;
   CString POSITION;
   
 //  BUYING** bUYING;
 //  STAFF* sTAFF;

protected:
public:


};

#endif