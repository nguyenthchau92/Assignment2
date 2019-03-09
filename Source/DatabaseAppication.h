#pragma once
#ifndef SINGLETON_H
#define SINGLETON_H

#include <afxdb.h>
#include <vector>
#include <map>
#include "Util.h"

class DatabaseAppication
{
private:
	static DatabaseAppication *instance;
	DatabaseAppication();

	CString connection;
	CDatabase database;
	
public:
	~DatabaseAppication();
	static DatabaseAppication *getInstance();

	void ConnectDB();
	void ExecuteQuery(CString query);
	void ExecuteQueryDistinctSelect(CString nameTable, CString field, std::vector<CString> &lstData);
	void ExecuteQuerySelect(CString nameTable, std::vector<std::vector<CString>> &lstData);
	void ExeQuerySelectOneRowWithCond(CString nameTable, CString contition, std::vector<CString> &lstData);
	void ExeQuerySelectWithCond(CString nameTable, CString contition, std::vector<std::vector<CString>> &lstData);
	void ExeQueryDeleteWithCond(CString nameTable, CString contition);
	void ExeQuerySelectWithBill(CString nameTable, CString year, CString month, std::vector<std::vector<CString>> &lstData);
	bool ExecuteQueryInsert(CString nameTable, std::vector<CString> listData);
	bool ExecuteQueryUpdate(CString nameTable, std::map<CString, CString> listData,
		std::map<CString, CString> listCondition);
	void ExeQuerySelectWithMultipleCond(CString nameTable, std::vector<CString> condition, std::vector<CString> &lstData);
	void ExeQuerySelecMultipleRowtWithMultipleCond(CString nameTable, std::vector<CString> lstCondition, std::vector<std::vector<CString>> &lstData);
	void ExecuteQueryDistinctSelectWithCondition(CString nameTable, CString field, CString condition, std::vector<std::vector<CString>> &lstData);
};

#endif
