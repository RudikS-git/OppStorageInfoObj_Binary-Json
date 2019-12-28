#include <iostream>
#include "RegistryOrganization.h"
#include <iterator>

void RegistryOrganization::AddObjectToList(Organization* pOrg)
{
	ListObjects.push_back(pOrg);
	cout << "Объект добавлен\n";
}

void RegistryOrganization::RemoveOrgan(int ind)
{
	list<Organization*>::iterator iter = ListObjects.begin();
	list<Organization*>::iterator iterend = ListObjects.end();
	
	if (iter == iterend)
	{
		cout << "Контейнер пуст";
		return;
	}
	else if (ListObjects.size()<=ind || ind<0)
	{
		cout << "По данному индексу не существует объекта";
		return;
	}

	advance(iter, ind);
	ListObjects.remove(*iter);
	cout << "Объект удален\n";
}

void RegistryOrganization::ShowListObj()
{
	list<Organization*>::iterator iter = ListObjects.begin();
	list<Organization*>::iterator iterend = ListObjects.end();
	
	for (int i = 0; iter != iterend; iter++, i++)
	{
		auto pListEl = (*iter);

		cout<< i << ") Имя организации: " << pListEl->GetName() << '\n';
		cout << "Год создания: " << pListEl->GetYear() << '\n';
		cout<< "Имя создателя: " << pListEl->GetOwner() << '\n';
		pListEl->ShowList();
	}
}

int RegistryOrganization::GetCount()
{
	return ListObjects.size();
}

Organization* RegistryOrganization::GetObject(int index)
{
	auto iter = ListObjects.begin();
	advance(iter, index);
	return (*iter);
}