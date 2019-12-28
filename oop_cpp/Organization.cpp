#include <iostream>
#include <string>
#include <iterator>
#include "Organization.h"
#include "MyConst.h"

using namespace std;

Organization::Organization()
{
	Name = nullptr;
	Owner = nullptr;
	Year = 0;
}

Organization::Organization(const char* name, int year, const char* owner)
{
	Name = new char[MaxLength];
	Owner = new char[MaxLength];
	Year = year;

	strcpy_s(Name, sizeof(char) * MaxLength, name);
	strcpy_s(Owner, sizeof(char) * MaxLength, owner);
}

Organization::~Organization()
{ 
	if(Name != nullptr) delete [] Name;
	if(Owner != nullptr) delete [] Owner;
}

int Organization::GetYear()
{
	return Year;
}

char* Organization::GetName()
{
	return Name;
}
char* Organization::GetOwner()
{
	return Owner;
}
