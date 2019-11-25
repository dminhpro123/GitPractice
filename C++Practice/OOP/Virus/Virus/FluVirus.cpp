#include "FluVirus.h"
#include <iostream>

# define RED 0xff0000
# define BLUE 0x0000ff

using namespace std;

FluVirus::FluVirus()
{
	this->DoBorn();
	this->InitResistance();
}

FluVirus::~FluVirus()
{
	this->DoDie();
}

void FluVirus::SetM_color(int m_color)
{
	this->m_color = m_color;
}

int FluVirus::GetM_color()
{
	return m_color;
}

void FluVirus::DoBorn()
{
	this->LoadADNInformation();
	int* colorArr = new int[2]{BLUE, RED};
	int index = rand() % 2;
	this->m_color = colorArr[index];
}

list<Virus *> FluVirus::DoClone()
{
	list<Virus*> listFluVirus;
	FluVirus* fluVirus = new FluVirus();
	fluVirus->SetM_color(this->GetM_color());
	fluVirus->SetM_dna(this->GetM_dna());
	fluVirus->SetM_resistance(this->GetM_resistance());
	listFluVirus.push_back(fluVirus);
	return listFluVirus;
}

void FluVirus::DoDie()
{
//	release all virus data
}

void FluVirus::InitResistance()
{
	int resistance;
	if (this->m_color == BLUE)
	{
		resistance = rand() % 11 + 10;
	}
	else
	{
		resistance = rand() % 6 + 10;
	}
	this->SetM_resistance(resistance);
}
