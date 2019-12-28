#include <iostream>
#include <cstring>
#include <iterator>
#include "MyConst.h"
#include "InsuranceCompany.h"

using namespace std;

InsuranceCompany::InsuranceCompany()
{
	_contractsCount = 0;
}

InsuranceCompany::InsuranceCompany(const char* name, int year, const char* owner, int contractsCount):Organization(name, year, owner)
{
	_contractsCount = contractsCount;
}

InsuranceCompany::~InsuranceCompany()
{
}

void InsuranceCompany::SetOwner(char* owner)
{
	if (Owner != nullptr) delete[] Owner;
	Owner = owner;
}

void InsuranceCompany::SetYear(int year)
{
	Year = year;
}

void InsuranceCompany::SetName(char* name)
{
	if (Name != nullptr) delete[] Name;
	Name = name;
}

int InsuranceCompany::GetValue()
{
	return _contractsCount;
}

void InsuranceCompany::SetContractCount(int contractsCount)
{
	if (contractsCount > 0)
	{
		_contractsCount = contractsCount;
	}
}

Organization::TypeObj InsuranceCompany::GetTypeObject()
{
	return INSURANCE;
}

void InsuranceCompany::ShowList()
{
	cout << "Кол - во контрактов: " << _contractsCount << "\n \n";
}