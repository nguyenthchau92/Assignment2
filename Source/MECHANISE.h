/***********************************************************************
 * Module:  MECHANISE.h
 * Author:  overflow
 * Modified: Saturday, February 16, 2019 2:43:17 PM
 * Purpose: Declaration of the class MECHANISE
 ***********************************************************************/

#if !defined(__MOTOBIKESTOREMANAGEMENT_MECHANISE_h)
#define __MOTOBIKESTOREMANAGEMENT_MECHANISE_h

#pragma once
#include "afxwin.h"

class MAINTAIN;
class STAFF;

class MECHANISE
{
public:
   CString STA_STAFFID;
   CString BRANCHID;
   double DATEOFBIRTH;
   CString NAMESTAFF;
   bool SEX;
   CString ADDRESS;
   int SALARY;
   CString POSITION;
   
   MAINTAIN** mAINTAIN;
   STAFF* sTAFF;

protected:
private:

};

#endif