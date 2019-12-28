#include <iostream>
#include <iterator>
#include "Plant.h"
#include "MyConst.h"

using namespace std;


Plant::Plant()
{
	_detailsCount = 0;
}

Plant::Plant(const char* name, int year, const char* owner, int detailsCount) :Organization(name, year, owner)
{
	_detailsCount = detailsCount;
}

Plant::~Plant()
{
}

void Plant::SetOwner(char* owner)
{
	if (Owner != nullptr) delete[] Owner;
	Owner = owner;
}

void Plant::SetYear(int year)
{
	Year = year;
}

void Plant::SetName(char* name)
{
	if (Name != nullptr) delete[] Name;
	Name = name;
}

void Plant::SetDetailsCount(int detailsCount)
{
	if (detailsCount > 0)
	{
		_detailsCount = detailsCount;
	}
}

int Plant::GetValue()
{
	return _detailsCount;
}

Organization::TypeObj Plant::GetTypeObject()
{
	return PLANT;
}

void Plant::ShowList()
{
	cout << "Кол - во деталей: " << _detailsCount << "\n \n";
}