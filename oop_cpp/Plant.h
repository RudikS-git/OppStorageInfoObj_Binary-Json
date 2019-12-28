#pragma once

#include "Organization.h"

class Plant: public Organization
{
private:
	int _detailsCount;
public:
	Plant();
	Plant(const char* name, int year, const char* owner, int detailsCount);
	~Plant();

	void SetOwner(char*);
	void SetYear(int);
	void SetName(char*);
	void SetDetailsCount(int);
	int GetValue();
	TypeObj GetTypeObject();

	void ShowList();

};