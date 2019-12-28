#pragma once
#include "RegistryOrganization.h"

class Binary
{
private:
	RegistryOrganization* _registryOrganization;
	const char PATH[59] = "C:\\Users\\RudikS\\Desktop\\oop_cpp\\object-desciption.txt";
	const char PATH_INFO_OBJECT[48] = "C:\\Users\\RudikS\\Desktop\\oop_cpp\\info-object.txt";
public:
	Binary(RegistryOrganization*);
	void Write();
	void Read();
	void LoadPar(ofstream&, char*);
	void UnLoadPar();
};