/***********************************************************************
 * Module:  MAINTAIN.h
 * Author:  overflow
 * Modified: Saturday, February 16, 2019 2:43:17 PM
 * Purpose: Declaration of the class MAINTAIN
 ***********************************************************************/

#if !defined(__MOTOBIKESTOREMANAGEMENT_MAINTAIN_h)
#define __MOTOBIKESTOREMANAGEMENT_MAINTAIN_h


#pragma once
#include "afxwin.h"

class CUSTOMER;
class MECHANISE;
class MOTOBIKE;

class MAINTAIN
{
public:
   double MAINTAINDATE;
   CString MAINTAININFORMATION;
   
   CUSTOMER* cUSTOMER;
   MECHANISE* mECHANISE;
   MOTOBIKE* mOTOBIKE;

protected:
private:

};

#endif