#include <iostream>
#include <fstream>
#include "binary.h"
#include "Organization.h"
#include "ShipCompany.h"
#include "Plant.h"
#include "InsuranceCompany.h"
#include "StructInfoObj.h"

Binary::Binary(RegistryOrganization* registryOrganization)
{
	_registryOrganization = registryOrganization;
}

void Binary::Write()
{
	if (_registryOrganization->GetCount() == 0)
	{
		cout << "В контейнере отсуствуют объекты для записи" << endl;
		return;
	}

	ofstream fo1(PATH_INFO_OBJECT, ios::binary);

	if (!fo1)
	{
		cout << "Не удалось создать файл списка объектов" << endl;
		return;
	}

	int count = _registryOrganization->GetCount();
	InfoObj infoObj;

	for (int i = 0; i < count; i++)
	{
		Organization* organization = _registryOrganization->GetObject(i);

		infoObj.typeObj = organization->GetTypeObject();
		infoObj.sizeName = strlen(organization->GetName())+1;
		infoObj.sizeOwner = strlen(organization->GetOwner())+1;
		infoObj.sizeYear = sizeof(organization->GetYear());
		infoObj.sizeValue = sizeof(organization->GetValue());

		fo1.write((char*)&infoObj, sizeof(infoObj));
	}
	
	fo1.close(); 

	ofstream fo2(PATH, ios::binary);

	if (!fo2)
	{
		cout << "Не удалось создать файл описания объектов" << endl;
		return;
	}

	for (int i = 0; i < _registryOrganization->GetCount(); i++)
	{
		Organization* organization = _registryOrganization->GetObject(i);
		LoadPar(fo2, organization->GetName());
		LoadPar(fo2, organization->GetOwner());
		unsigned int year = organization->GetYear();
		unsigned int value = organization->GetValue();
		fo2.write((char*)&year, sizeof(unsigned int));
		fo2.write((char*)&value, sizeof(unsigned int));
	}

	fo2.close();
}

// typeObject Name Year Owner Value
void Binary::Read()
{
	if (_registryOrganization->GetCount() != 0) 
	{
		cout << "В контейнере отсуствуют объекты для записи" << endl;
		return;
	}

	ifstream fi2(PATH_INFO_OBJECT, ios::binary);

	if (!fi2) 
	{
		cout << "Не удалось открыть список объектов" << endl;
		return;
	}

	fi2.seekg(0, ios::end); // смещаемся в конец
	int len = fi2.tellg();
	int count = len / sizeof(InfoObj); // кол-во объектов
	fi2.seekg(0, ios::beg); // смешаемся в начало
	InfoObj* infoObj = new InfoObj[count];

	fi2.read((char*)infoObj, sizeof(InfoObj) * count);

	fi2.close();

	ifstream fi1(PATH, ios::binary);

	
	if (!fi1)
	{
		cout << "Не удалось открыть описание объектов" << endl;
		return;
	}

	for (int i = 0; i < count; i++)
	{
		Organization* organization = NULL;
		switch (infoObj[i].typeObj)
		{
			case Organization::TypeObj::SHIP:
			{
				organization = new ShipCompany();
				break;
			}
			case Organization::TypeObj::PLANT:
			{
				organization = new Plant();
				break;
			}
			case Organization::TypeObj::INSURANCE:
			{
				organization = new InsuranceCompany();
				break;
			}
		}
		
		char* name = new char[255];
		char* owner = new char[255];
		int year;
		int value;

		fi1.read((char*)name, infoObj[i].sizeName);
		//name[infoObj[i].sizeName] = '\0';
		//fi1.seekg(infoObj[i].sizeName);
		fi1.read((char*)owner, infoObj[i].sizeOwner);
		//owner[infoObj[i].sizeOwner] = '\0';
		//fi1.seekg(infoObj[i].sizeOwner);
		fi1.read((char*)&year, infoObj[i].sizeYear);
		//fi1.seekg(infoObj[i].sizeYear);
		fi1.read((char*)&value, infoObj[i].sizeValue);
		//fi1.seekg(infoObj[i].sizeValue);

		Organization::TypeObj typeObj = infoObj[i].typeObj;

		switch (typeObj)
		{
			case Organization::TypeObj::SHIP:
			{

				_registryOrganization->AddObjectToList(new ShipCompany(name, 
																	   year, 
																	   owner,
																	   value));
				break;
			}

			case Organization::TypeObj::PLANT:
			{
				_registryOrganization->AddObjectToList(new Plant(name,
					year,
					owner,
					value));
				break;
			}

			case Organization::TypeObj::INSURANCE:
			{
				_registryOrganization->AddObjectToList(new InsuranceCompany(name,
					year,
					owner,
					value));
				break;
			}
		}
		delete[]name;
		delete[]owner;
		delete organization;
	}
}

void Binary::LoadPar(ofstream &of, char* str)
{
	int i = 0;
	unsigned int length = strlen(str) + 1;
	while (i != length)
	{
		of.write((char*)&str[i], sizeof(char));
		i++;
	}
}

void Binary::UnLoadPar()
{

}