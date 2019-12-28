#pragma once

#include "Organization.h"

class ShipCompany: public Organization
{
private:
	int _shipCount;
public:
	ShipCompany();
	ShipCompany(const char* name, int year, const char* owner, int shipCount);
	~ShipCompany();

	void SetOwner(char*);
	void SetYear(int);
	void SetName(char*);
	int GetValue();
	TypeObj GetTypeObject();

	void SetShipCount(int);
	void ShowList();
};