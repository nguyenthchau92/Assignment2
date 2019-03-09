/***********************************************************************
 * Module:  BRANCH.h
 * Author:  overflow
 * Modified: Saturday, February 16, 2019 2:43:17 PM
 * Purpose: Declaration of the class BRANCH
 ***********************************************************************/

#if !defined(__MOTOBIKESTOREMANAGEMENT_BRANCH_h)
#define __MOTOBIKESTOREMANAGEMENT_BRANCH_h

#pragma once
#include "afxwin.h"

class STAFF;

class BRANCH
{
public:
   CString BRANCHID;
   CString BRANCHNAME;
   CString BRANCHLOCATION;
   
   STAFF** work;

protected:
private:

};

#endif