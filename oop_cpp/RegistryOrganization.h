#pragma once

#include <list>
#include "Organization.h"

using namespace std;

class RegistryOrganization
{
private:
	list<Organization*> ListObjects;
public:
	void AddObjectToList(Organization*);
	void RemoveOrgan(int);
	void ShowListObj();
	int GetCount();
	Organization* GetObject(int);
};