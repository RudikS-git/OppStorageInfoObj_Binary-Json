#pragma once

class Organization
{
public:
	enum TypeObj
	{
		SHIP = 0,
		PLANT,
		INSURANCE
	};

	Organization();
	Organization(const char* name, int year, const char* owner);
	virtual ~Organization();

	virtual void SetYear(int) = 0;
	virtual void SetName(char*) = 0;
	virtual void SetOwner(char*) = 0;
	virtual TypeObj GetTypeObject() = 0;
	virtual int GetValue() = 0;

	int GetYear();
	char* GetName();
	char* GetOwner();

	virtual void ShowList() = 0;

protected:
	char* Name; // Название организации
	int Year; // год создания
	char* Owner; // Владелец
};
