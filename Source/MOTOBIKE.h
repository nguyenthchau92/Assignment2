/***********************************************************************
 * Module:  MOTOBIKE.h
 * Author:  overflow
 * Modified: Saturday, February 16, 2019 2:43:17 PM
 * Purpose: Declaration of the class MOTOBIKE
 ***********************************************************************/

#if !defined(__MOTOBIKESTOREMANAGEMENT_MOTOBIKE_h)
#define __MOTOBIKESTOREMANAGEMENT_MOTOBIKE_h

#pragma once
#include "afxwin.h"

class BUYING;
class MAINTAIN;

class MOTOBIKE
{
private:
   CString MOTOBIKEID;
   CString MOTOBIKETYPE;
   CString MOTOBIKECOLOR;
   CString PRODUCER;
   CString NAME;
   int YEAR;
   int PRICE;
   bool STATUS;
   
   BUYING** bUYING;
   MAINTAIN** mAINTAIN;

protected:
private:
public:
	MOTOBIKE()
	{
		STATUS = false;
		PRICE = 0;
	}

	// set function
	void setMOTOBIKEID(CString MOTOBIKEID)
	{
		this->MOTOBIKEID = MOTOBIKEID.Trim();
	}

	void setMOTOBIKETYPE(CString MOTOBIKETYPE)
	{
		this->MOTOBIKETYPE = MOTOBIKETYPE.Trim();
	}

	void setMOTOBIKECOLOR(CString MOTOBIKECOLOR)
	{
		this->MOTOBIKECOLOR = MOTOBIKECOLOR.Trim();
	}

	void setPRODUCER(CString PRODUCER)
	{
		this->PRODUCER = PRODUCER.Trim();
	}

	void setYEAR(int YEAR)
	{
		this->YEAR = YEAR;
	}

	void setPRICE(int PRICE)
	{
		this->PRICE = PRICE;
	}

	int getPRICE()
	{
		return this->PRICE;
	}

	void setNAME(CString NAME)
	{
		this->NAME = NAME;
	}

	CString getNAME()
	{
		return this->NAME;
	}


	void setSTATUS(bool STATUS)
	{
		this->STATUS = STATUS;
	}

	// get function
	CString getMOTOBIKEID()
	{
		return MOTOBIKEID;
	}

	CString getMOTOBIKETYPE()
	{
		return MOTOBIKETYPE;
	}

	CString getMOTOBIKECOLOR()
	{
		return MOTOBIKECOLOR;
	}

	CString getPRODUCER()
	{
		return PRODUCER;
	}

	int getYEAR()
	{
		return YEAR;
	}

	bool getSTATUS()
	{
		return STATUS;
	}

};

#endif