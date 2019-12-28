#include <iostream>
#include "RegistryOrganization.h"
#include <iterator>

void RegistryOrganization::AddObjectToList(Organization* pOrg)
{
	ListObjects.push_back(pOrg);
	cout << "������ ��������\n";
}

void RegistryOrganization::RemoveOrgan(int ind)
{
	list<Organization*>::iterator iter = ListObjects.begin();
	list<Organization*>::iterator iterend = ListObjects.end();
	
	if (iter == iterend)
	{
		cout << "��������� ����";
		return;
	}
	else if (ListObjects.size()<=ind || ind<0)
	{
		cout << "�� ������� ������� �� ���������� �������";
		return;
	}

	advance(iter, ind);
	ListObjects.remove(*iter);
	cout << "������ ������\n";
}

void RegistryOrganization::ShowListObj()
{
	list<Organization*>::iterator iter = ListObjects.begin();
	list<Organization*>::iterator iterend = ListObjects.end();
	
	for (int i = 0; iter != iterend; iter++, i++)
	{
		auto pListEl = (*iter);

		cout<< i << ") ��� �����������: " << pListEl->GetName() << '\n';
		cout << "��� ��������: " << pListEl->GetYear() << '\n';
		cout<< "��� ���������: " << pListEl->GetOwner() << '\n';
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