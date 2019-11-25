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

void DengueVirus::SetM_protein(char* m_protein)
{
	strcpy(this->m_protein,m_protein);
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
	strcpy(this->m_protein, protein.c_str());
}

list<Virus*> DengueVirus::DoClone()
{
	list<Virus *> listDengueVirus;
	for (int i = 0; i < 2; i++)
	{
		DengueVirus* dengueVirus = new DengueVirus();
		dengueVirus->SetM_protein(this->GetM_protein());
		dengueVirus->SetM_dna(this->GetM_dna());
		dengueVirus->SetM_resistance(this->GetM_resistance());
		listDengueVirus.push_back(dengueVirus);
	}
	return listDengueVirus;
}

void DengueVirus::DoDie()
{
//	release all virus data
}

void DengueVirus::InitResistance()
{
	int resistance;
	// random value for color NS3
	string protein = this->m_protein;
	if (protein == "NS3")
	{
		resistance = rand() % 10 + 1;
	}
	// random value for color NS5;
	else if (protein == "NS5")
	{
		resistance = rand() % 10 + 11;
	}
	else
	{
		resistance = rand() % 10 + 21;
	}

	this->SetM_resistance(resistance);
}
