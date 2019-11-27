#pragma once
#include "list"
#include "Virus.h"
#include "FluVirus.h"
#include "DengueVirus.h"

class Patient
{
private:
	int m_resistance;
	list<Virus *> m_virusList;
	int m_state;
public:
	Patient();
	~Patient();
	void InitResistance();
	void DoStart();
	void TakeMedicine(int);
	void DoDie();
	int  GetState();

	list<Virus*> getVirusList();
};
