#include <iostream>
#include <locale>
#include "InsuranceCompany.h"
#include "Plant.h"
#include "ShipCompany.h"
#include "RegistryOrganization.h"
#include "Json.h"
#include "binary.h"

using namespace std;

#define TypeRecord 1 // 0 - binary | 1 - json

void CreateOrganization(Organization*);

int main()
{
	// организация, страховая компания, судостроительная компания, завод;
	setlocale(LC_ALL, "rus");

	enum Selection
	{
		ADD,
		DEL,
		SHOW,
		EXIT
	};

	int choice;
	RegistryOrganization registryOrganization;
	
	

#if TypeRecord == 1
	Json json(&registryOrganization); // работа с json
	json.Read();

#else
	Binary binary(&registryOrganization); // работа с бинарником
	binary.Read();

	//binary.Write();
	//registryOrganization.AddObjectToList(new Plant("zavod", 2000, "owner", 12));
	//registryOrganization.AddObjectToList(new ShipCompany("sudo", 2005, "rud", 2000));
#endif

	system("cls");


	while (true)
	{
		cout << "Добавить объект - 0\n";
		cout << "Удалить объект - 1\n";
		cout << "Показать объекты - 2\n";
		cout << "Выйти из программы - 3\n \n";
		cin >> choice;

		if (choice < 0 || choice>4)
		{
			cout << "Неверно введено действие!\n";
			continue;
		}

		switch (choice)
		{
			case ADD:
			{
				cout << "Судостроительная компания - 0\n";
				cout << "Завод - 1\n";
				cout << "Страховая компания - 2\n";

				cin >> choice;
				if (choice < 0 || choice>3)
				{
					cout << "Такого объекта нет!\n";
					continue;
				}

				switch (choice)
				{
					case Organization::SHIP:
					{
						int shipCount;
						ShipCompany *pShipCompany = new ShipCompany();
						CreateOrganization(pShipCompany);
						cout << "Кол-во произвед суден:\n";
						cin >> shipCount;
						if (shipCount < 1)
						{
							cout << "Некорректное значение";
							break;
						}
						pShipCompany->SetShipCount(shipCount);
						registryOrganization.AddObjectToList(pShipCompany);

						#if TypeRecord == 1
							json.Write();
						#else
						binary.Write();
						#endif					
						break;
					}
					case Organization::PLANT:
					{
						int detailsCount;
						Plant* pPlant = new Plant();
						CreateOrganization(pPlant);
						cout << "Кол-во произвед деталей:\n";
						cin >> detailsCount;
						if (detailsCount < 1)
						{
							cout << "Некорректное значение";
							break;
						}
						pPlant->SetDetailsCount(detailsCount);
						registryOrganization.AddObjectToList(pPlant);
						#if TypeRecord == 1
							json.Write();
						#else
							binary.Write();
						#endif		
						break;
					}
					case Organization::INSURANCE:
					{
						int contractsCount;
						InsuranceCompany* pInsuranceCompany = new InsuranceCompany();
						CreateOrganization(pInsuranceCompany);
						cout << "Кол-во заключ контрактов:\n";
						cin >> contractsCount;

						if (contractsCount < 1)
						{
							cout << "Некорректное значение";
							break;
						}
						pInsuranceCompany->SetContractCount(contractsCount);
						system("cls");
						registryOrganization.AddObjectToList(pInsuranceCompany);
						#if TypeRecord == 1
							json.Write();
						#else
							binary.Write();
						#endif		
						break;
					}
				}

				break;
			}

			case DEL:
			{
				registryOrganization.ShowListObj();
				cout << "Введите номер индекса для удаления:\n";
				cin >> choice;

				registryOrganization.RemoveOrgan(choice);
				
				#if TypeRecord == 1
					json.Write();
				#else
					binary.Write();
				#endif		
				break;
			}

			case SHOW:
			{
				registryOrganization.ShowListObj();
				break;
			}

			case EXIT:
			{

				//binary.Write();
				return 0;
			}
		}
		cout << '\n';
	}
//	binary.Write();
}

void CreateOrganization(Organization* pOrganization)
{
	int year;
	char* name = new char[255];
	char* owner = new char[255];

	cout << "Введите имя организации:\n";
	cin >> name;
	pOrganization->SetName(name);

	cout << "Введите год создания организации:\n";
	cin >> year;
	pOrganization->SetYear(year);

	cout << "Введите владельца организации:\n";
	cin >> owner;
	pOrganization->SetOwner(owner);

}

