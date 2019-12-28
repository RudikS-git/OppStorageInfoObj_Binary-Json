#include <iostream>
#include <iterator>
#include "ShipCompany.h"
#include "MyConst.h"

using namespace std;

ShipCompany::ShipCompany()
{
	_shipCount = 0;
}

ShipCompany::ShipCompany(const char* name, int year, const char* owner, int shipCount) :Organization(name, year, owner)
{
	_shipCount = shipCount;
}

ShipCompany::~ShipCompany()
{
}

void ShipCompany::SetOwner(char* owner)
{
	if (Owner != nullptr) delete[] Owner;
	Owner = owner;
}

void ShipCompany::SetYear(int year)
{
	Year = year;
}

void ShipCompany::SetName(char* name)
{
	if (Name != nullptr) delete[] Name;
	Name = name;
}

void ShipCompany::SetShipCount(int shipCount)
{
	if (shipCount > 0)
	{
		_shipCount = shipCount;
	}
}

int ShipCompany::GetValue()
{
	return _shipCount;
}

Organization::TypeObj ShipCompany::GetTypeObject()
{
	return SHIP;
}

void ShipCompany::ShowList()
{
	cout << "Кол - во суден: " << _shipCount << "\n \n";
}