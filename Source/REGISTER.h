/***********************************************************************
 * Module:  REGISTER.h
 * Author:  overflow
 * Modified: Saturday, February 16, 2019 2:43:17 PM
 * Purpose: Declaration of the class REGISTER
 ***********************************************************************/

#if !defined(__MOTOBIKESTOREMANAGEMENT_REGISTER_h)
#define __MOTOBIKESTOREMANAGEMENT_REGISTER_h

#pragma once
#include "afxwin.h"

class STAFF;

class REGISTER
{
private:
   CString USERNAME;
   CString PASSWORD;
   
   STAFF* sTAFF;

protected:
public:
	void SetUserName(CString USERNAME)
	{
		this->USERNAME = USERNAME;
	}

	CString GetUSERNAME()
	{
		return USERNAME;
	}

	void SetPassword(CString PASSWORD)
	{
		this->PASSWORD = PASSWORD;
	}

	CString GetPassword()
	{
		return PASSWORD;
	}

};


#endif