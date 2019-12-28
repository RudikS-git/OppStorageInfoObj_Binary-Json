#pragma once

#include "Organization.h"
#include "MyConst.h"

class InsuranceCompany: public Organization
{
private:
	int _contractsCount;
public:
	InsuranceCompany();
	InsuranceCompany(const char*, int, const char*, int contractsCount);
	~InsuranceCompany();

	void SetOwner(char*);
	void SetYear(int);
	void SetName(char*);
	int GetValue();
	TypeObj GetTypeObject();

	void SetContractCount(int);
	void ShowList();
};