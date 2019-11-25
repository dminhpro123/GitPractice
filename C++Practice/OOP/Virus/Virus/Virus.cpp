#include <iostream>
#include <fstream>
#include <string>
#include "Virus.h"

using namespace std;

Virus::Virus()
{
}

Virus::Virus(char* m_dna, int m_resistance)
{
	this->m_dna = m_dna;
	this->m_resistance = m_resistance;
}

Virus::Virus(const Virus& virus)
{
	this->m_dna = virus.m_dna;
	this->m_resistance = virus.m_resistance;
}

void Virus::SetM_dna(char* m_dna)
{
	this->m_dna = m_dna;
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
	m_resistance = m_resistance - medicine_resistance;
}
