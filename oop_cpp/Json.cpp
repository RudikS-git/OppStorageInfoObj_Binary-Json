#include <iostream>
#include <fstream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/reader.h"
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/ostreamwrapper.h"
#include "Json.h"
#include "RegistryOrganization.h"
#include "InsuranceCompany.h"
#include "Plant.h"
#include "ShipCompany.h"

using namespace std;
using namespace rapidjson;

Json::Json(RegistryOrganization* regOrganization)
{
	_regOrganization = regOrganization;
}

void Json::Write()
{
	if (_regOrganization->GetCount() == 0)
	{
		return;
	}

	Document document;
	document.SetArray();
	auto& allocator = document.GetAllocator();
	for (int i = 0; i < _regOrganization->GetCount(); i++)
	{

		Organization* organization = _regOrganization->GetObject(i);

		Value jsonVal;
		jsonVal.SetObject();
		jsonVal.AddMember("TypeObject", organization->GetTypeObject(), allocator);

		string buf = organization->GetName();
		Value bufVal;
		bufVal.SetString(organization->GetName(), allocator);
		jsonVal.AddMember("Name", bufVal, allocator);

		jsonVal.AddMember("Year", organization->GetYear(), allocator);

		buf = organization->GetOwner();
		bufVal.SetString(buf.c_str(), allocator);
		jsonVal.AddMember("Owner", bufVal, allocator);

		jsonVal.AddMember("Value", organization->GetValue(), allocator);

		document.PushBack(jsonVal, allocator);
	}
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	document.Accept(writer);
	string json = buffer.GetString();

	ofstream ofs(PATH);
	ofs << json << endl;
	ofs.close();
}

void Json::Read()
{
	Document document;
	ifstream ifs(PATH);

	if (!ifs)
	{
		return;
	}
	// закрытие потока после выхода из видимости метода

	IStreamWrapper isw(ifs);
	document.ParseStream(isw);

	if (!document.IsArray())
	{
		return;
	}

	for (int i = 0; i < document.Size(); i++)
	{
		auto typeObj = (Organization::TypeObj)document[i]["TypeObject"].GetInt();
		const char* name = document[i]["Name"].GetString();
		int year = document[i]["Year"].GetInt();
		const char* owner = document[i]["Owner"].GetString();
		int val = document[i]["Value"].GetInt();

		switch (typeObj)
		{
			case Organization::TypeObj::SHIP:
			{
				_regOrganization->AddObjectToList(new ShipCompany(name, year, owner, val));
				break;
			}

			case Organization::TypeObj::PLANT:
			{
				_regOrganization->AddObjectToList(new Plant(name, year, owner, val));
				break;
			}

			case Organization::TypeObj::INSURANCE:
			{
				_regOrganization->AddObjectToList(new InsuranceCompany(name, year, owner, val));
				break;
			}
		}
	}
	ifs.close();
}

