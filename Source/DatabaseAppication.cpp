#include "stdafx.h"
#include "DatabaseAppication.h"

DatabaseAppication * DatabaseAppication::instance = NULL;

DatabaseAppication::DatabaseAppication()
{
}

DatabaseAppication::~DatabaseAppication()
{
}

void DatabaseAppication::ConnectDB()
{
	if (database.IsOpen())
	{
		//MessageBox(_T("The database has been connected to applicaiton"));
	}
	connection = _T("Driver={SQL Server Native Client 11.0};Server=IPHONE-6-PLUS\\SQLSERVER2014;Database=MotobikeStoreManagement;Trusted_Connection=Yes;Uid=sa;Pwd=12345678;");
	if (database.OpenEx(connection, CDatabase::useCursorLib))
	{
		//		MessageBox(_T("Connected database successfully"));
	}
}

DatabaseAppication* DatabaseAppication::getInstance()
{
	if (instance == NULL)
		instance = new DatabaseAppication;
	return instance;
}

// just return the first row when satisfy the condition
void DatabaseAppication::ExeQuerySelectOneRowWithCond(CString nameTable, CString condition, std::vector<CString> &lstData)
{
	CString query = L"select * from " + nameTable + L" where " + condition;
	//MessageBox(NULL, query, L"", 0);
	CRecordset recordset(&database);
	CString temp;
	recordset.Open(CRecordset::forwardOnly, query, CRecordset::readOnly);
	if(!recordset.IsEOF())
	{
		int len = recordset.GetODBCFieldCount();
		for (int i = 0; i < len; i++)
		{
			recordset.GetFieldValue(i, temp);
			lstData.push_back(temp);
		}
	}
}

void DatabaseAppication::ExeQuerySelectWithBill(CString nameTable, CString year, CString month, std::vector<std::vector<CString>> &lstData)
{
	CString query = L"select * from " + nameTable + L" where MONTH(TIMEINVOICE)= " + month + L" AND YEAR(TIMEINVOICE)= " + year;
	//MessageBox(NULL, query, L"", 0);
	CRecordset recordset(&database);
	CString temp;
	recordset.Open(CRecordset::forwardOnly, query, CRecordset::readOnly);
	while (!recordset.IsEOF())
	{
		std::vector<CString> row;
		int len = recordset.GetODBCFieldCount();
		for (int i = 0; i < len; i++)
		{
			recordset.GetFieldValue(i, temp);
			row.push_back(temp);
		}
		lstData.push_back(row);
		recordset.MoveNext();
	}
}

void DatabaseAppication::ExeQueryDeleteWithCond(CString nameTable, CString contition)
{
	CRecordset recordset(&database);
	CString query = L"delete * from " + nameTable + L" where " + contition;
	recordset.Open(CRecordset::forwardOnly, query, CRecordset::readOnly);
}

void DatabaseAppication::ExeQuerySelectWithCond(CString nameTable, CString condition, std::vector<std::vector<CString>> &lstData)
{
	CString query = L"select * from " + nameTable + L" where " + condition;
	//MessageBox(NULL, query, L"", 0);
	CRecordset recordset(&database);
	CString temp;
	recordset.Open(CRecordset::forwardOnly, query, CRecordset::readOnly);
	while (!recordset.IsEOF())
	{
		std::vector<CString> row;
		int len = recordset.GetODBCFieldCount();
		for (int i = 0; i < len; i++)
		{
			recordset.GetFieldValue(i, temp);
			row.push_back(temp);
		}
		lstData.push_back(row);
		recordset.MoveNext();
	}
}

// just return the first row when satisfy the condition
void DatabaseAppication::ExeQuerySelecMultipleRowtWithMultipleCond(CString nameTable, std::vector<CString> lstCondition, std::vector<std::vector<CString>> &lstData)
{
	CString query = L"select * from " + nameTable + L" where ";
	for (int i = 0; i < lstCondition.size(); i++)
	{
		query += lstCondition[i];
		if (i == lstCondition.size() - 1)
			break;
		query += " and ";
	}

	CRecordset recordset(&database);
	CString temp;
	recordset.Open(CRecordset::forwardOnly, query, CRecordset::readOnly);
	while (!recordset.IsEOF())
	{
		std::vector<CString> row;
		int len = recordset.GetODBCFieldCount();
		for (int i = 0; i < len; i++)
		{
			recordset.GetFieldValue(i, temp);
			row.push_back(temp);
		}
		lstData.push_back(row);
		recordset.MoveNext();
	}
}

// just return the first row when satisfy the condition
void DatabaseAppication::ExeQuerySelectWithMultipleCond(CString nameTable, std::vector<CString> lstCondition, std::vector<CString> &lstData)
{
	CString query = L"select * from " + nameTable + L" where ";
	for (int i = 0; i < lstCondition.size(); i++)
	{
		query += lstCondition[i];
		if (i == lstCondition.size() - 1)
			break;
		query += " and ";
	}
	CRecordset recordset(&database);
	CString temp;
	recordset.Open(CRecordset::forwardOnly, query, CRecordset::readOnly);
	if (!recordset.IsEOF())
	{
		int len = recordset.GetODBCFieldCount();
		for (int i = 0; i < len; i++)
		{
			recordset.GetFieldValue(i, temp);
			lstData.push_back(temp);
		}
	}
}

void DatabaseAppication::ExecuteQuerySelect(CString nameTable, std::vector<std::vector<CString>> &lstData)
{
	CString query = L"Select * from " + nameTable;
	CRecordset recordset(&database);
	CString temp;
	recordset.Open(CRecordset::forwardOnly, query, CRecordset::readOnly);
	while (!recordset.IsEOF())
	{
		std::vector<CString> row;
		int len = recordset.GetODBCFieldCount();
		for (int i = 0; i < len; i++)
		{
			recordset.GetFieldValue(i, temp);
			row.push_back(temp);
		}
		lstData.push_back(row);
		recordset.MoveNext();
	}
}

void DatabaseAppication::ExecuteQueryDistinctSelect(CString nameTable, CString field, std::vector<CString> &lstData)
{
	CString query = L"Select distinct " + field + L" from " + nameTable;
	CRecordset recordset(&database);
	CString temp;
	recordset.Open(CRecordset::forwardOnly, query, CRecordset::readOnly);
	while (!recordset.IsEOF())
	{
		int idx = 0;
		recordset.GetFieldValue(idx, temp);
		lstData.push_back(temp);
		recordset.MoveNext();
	}
}

void DatabaseAppication::ExecuteQueryDistinctSelectWithCondition(CString nameTable, CString field, CString condition, std::vector<std::vector<CString>> &lstData)
{
	CString query = L"Select distinct " + field + L" from " + nameTable + L" where " + condition;
	CRecordset recordset(&database);
	CString temp;
	recordset.Open(CRecordset::forwardOnly, query, CRecordset::readOnly);
	while (!recordset.IsEOF())
	{
		std::vector<CString> row;
		int len = recordset.GetODBCFieldCount();
		for (int i = 0; i < len; i++)
		{
			recordset.GetFieldValue(i, temp);
			row.push_back(temp);
		}
		lstData.push_back(row);
		recordset.MoveNext();
	}
}


void DatabaseAppication::ExecuteQuery(CString query)
{
	database.ExecuteSQL(query);
}

bool DatabaseAppication::ExecuteQueryInsert(CString nameTable, std::vector<CString> listData)
{
	bool ret = true;
	try
	{
		CString query = L"insert into " + nameTable + L" values(";
		for (int i = 0; i < listData.size(); i++)
		{
			if (i != listData.size() - 1)
				query += listData[i] + L",";
			else
				query += listData[i];
		}

		query += L")";
		database.ExecuteSQL(query);
	}
	catch (... )
	{
		ret = false;
	}
	return ret;
}

bool DatabaseAppication::ExecuteQueryUpdate(CString nameTable, std::map<CString, CString> listData, 
				std::map<CString, CString> listCondition)
{
	int ret = true;
	try
	{
		CString query = L"UPDATE " + nameTable + L" SET ";
		// Create a map iterator and point to beginning of map
		std::map<CString, CString>::iterator it = listData.begin();
		// Iterate over the map using Iterator till end.
		while (it != listData.end())
		{
			// Accessing KEY from element pointed by it.
			CString fieldName = it->first;
			CString value = it->second;
			it++;
			// handle text
			if (it != listData.end())
				query += fieldName + L"= " + value + L",";
			else
				query += fieldName + L"=" + value;

		}

		query += L" WHERE ";
		std::map<CString, CString>::iterator it2 = listCondition.begin();

		// Iterate over the map using Iterator till end.
		while (it2 != listCondition.end())
		{
			// Accessing KEY from element pointed by it.
			CString fieldName = it2->first;
			CString value = it2->second;
			// handle text
			it2++;
			if (it2 != listCondition.end())
				query += fieldName + L"= " + value + L",";
			else
				query += fieldName + L"=" + value;

		}

		database.ExecuteSQL(query);
	}
	catch (...)
	{
		ret = false;
	}
	return ret;
}



