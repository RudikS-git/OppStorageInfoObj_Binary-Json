#pragma once
#include "RegistryOrganization.h"
#include "rapidjson/document.h"

class Json
{
private:
	RegistryOrganization* _regOrganization;
	const char PATH [59] = "C:\\Users\\RudikS\\Desktop\\oop_cpp\\object-desciption.json";
public:
	Json(RegistryOrganization*);
	void Write();
	void Read();
};