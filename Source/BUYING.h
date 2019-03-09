/***********************************************************************
 * Module:  BUYING.h
 * Author:  overflow
 * Modified: Saturday, February 16, 2019 2:43:17 PM
 * Purpose: Declaration of the class BUYING
 ***********************************************************************/

#if !defined(__MOTOBIKESTOREMANAGEMENT_BUYING_h)
#define __MOTOBIKESTOREMANAGEMENT_BUYING_h

#include "SALER.h"

class CUSTOMER;
class MOTOBIKE;
class SALER;

class BUYING
{
private:
   CString BUYDATE;
   bool PAID;
   
   SALER saler;
   CUSTOMER customer;
   MOTOBIKE motobike;
   

protected:
public:
	BUYING()
	{

	}
	// set function
	void setBUYDATE(CString BUYDATE)
	{
		this->BUYDATE = BUYDATE.Trim();
	}

	void setPAID(bool PAID)
	{
		this->PAID = PAID;
	}

	void setCUSTOMER(CUSTOMER customer)
	{
		this->customer = customer;
	}

	void setMOTOBIKE(MOTOBIKE motobike)
	{
		this->motobike = motobike;
	}
	// get function
	void setSALER(SALER saler)
	{
		this->saler = saler;
	}

	CString getBUYDATE()
	{
		return this->BUYDATE;
	}

	bool getPAID(bool PAID)
	{
		return this->PAID;
	}

	CUSTOMER getCUSTOMER()
	{
		return this->customer;
	}

	MOTOBIKE getMOTOBIKE()
	{
		return this->motobike;
	}

	SALER getSALER()
	{
		return this->saler;
	}

};

#endif