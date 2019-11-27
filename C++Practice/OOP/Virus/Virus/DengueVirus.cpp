#pragma warning(disable : 4996)
#include "DengueVirus.h"
#include <iostream>
#include <string>

using namespace std;

DengueVirus::DengueVirus()
{
	this->DoBorn();
	this->InitResistance();
}

DengueVirus::~DengueVirus()
{
	this->DoDie();
}

DengueVirus::DengueVirus(const DengueVirus& dengueVirus) : Virus(dengueVirus)
{
	this->m_protein = dengueVirus.m_protein;
}

void DengueVirus::SetM_protein(char* protein)
{
	strcpy(this->m_protein,protein);
}

char* DengueVirus::GetM_protein()
{
	return this->m_protein;
}

void DengueVirus::DoBorn()
{
	this->LoadADNInformation();
	string* proteinArray = new string[3]{ "NS3", "NS5", "E" };
	int index = rand() % 3;
	string protein = proteinArray[index];
	this->m_protein = new char(4);
	strcpy(this->m_protein, protein.c_str());
}

list<Virus*> DengueVirus::DoClone()
{
	list<Virus *> listDengueVirus;
	for (int i = 0; i < 2; i++)
	{
		DengueVirus* dengueVirus = new DengueVirus();
		listDengueVirus.push_back(dengueVirus);
	}
	return listDengueVirus;
}

void DengueVirus::DoDie()
{
	cout << "Dengue died\n";
}

void DengueVirus::InitResistance()
{
	int resistance;
	// random value for color NS3
	string protein = this->m_protein;
	if (protein.compare("NS3"))
	{
		resistance = rand() % 10 + 1;
	}
	// random value for color NS5;
	else if (protein.compare("NS5"))
	{
		resistance = rand() % 10 + 11;
	}
	else
	{
		resistance = rand() % 10 + 21;
	}

	this->SetM_resistance(resistance);
}
