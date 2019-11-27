#pragma warning(disable : 4996)
#include <iostream>
#include <fstream>
#include <string>
#include "Virus.h"

using namespace std;

Virus::Virus()
{
//
}

Virus::Virus(char* dna, int resistance)
{
	this->m_dna = dna;
	this->m_resistance = resistance;
}

Virus::~Virus()
{
//
}

Virus::Virus(const Virus& virus)
{
	this->m_dna = virus.m_dna;
	this->m_resistance = virus.m_resistance;
}

void Virus::SetM_dna(char* dna)
{
	this->m_dna = dna;
}

char* Virus::GetM_dna()
{
	return m_dna;
}



void Virus::SetM_resistance(int m_resistance)
{
	this->m_resistance = m_resistance;
}

int Virus::GetM_resistance()
{
	return m_resistance;
}

void Virus::LoadADNInformation()
{
	ifstream loadVirusDNA("ATGX.bin");

	string load;
	getline(loadVirusDNA, load);
	this->m_dna = new char[load.length() + 1];
	strcpy(this->m_dna, load.c_str());

	loadVirusDNA.close();
}

void Virus::ReduceResistance(int medicine_resistance)
{
	this->m_resistance = this->m_resistance - medicine_resistance;
}
