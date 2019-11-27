#include "Patient.h"
#include "Virus.h"
#include "FluVirus.h"
#include "DengueVirus.h"
#include <iostream>

using namespace std;

Patient::Patient()
{
	this->InitResistance();
	this->DoStart();
}

Patient::~Patient()
{
	this->DoDie();
}

void Patient::InitResistance()
{
	int resistance = rand() % 8001 + 1000;
	this->m_resistance = resistance;
}

void Patient::DoStart()
{
	int numVirus = rand() % 11 + 10;
	for (int i = 0; i < numVirus; i++)
	{
		//type of virus: 0 - flu, 1 - dengue
		int typeOfVirus = rand() % 2;

		if (typeOfVirus == 1) {
			Virus* virus = new FluVirus();
			this->m_virusList.push_back(virus);
		}
		else {
			Virus* virus = new DengueVirus();
			this->m_virusList.push_back(virus);
		}
	}
	this->m_state = 1;
}

void Patient::TakeMedicine(int medicine_resistance)
{
	int ResistanceVirus;
	list<Virus*>::iterator it = this->m_virusList.begin();

	while (it != this->m_virusList.end())
	{
		(*it)->ReduceResistance(medicine_resistance);
		if ((*it)->GetM_resistance() > 0)
		{
			list<Virus*> cloneVirus = (*it)->DoClone();
			this->m_virusList.insert(it, cloneVirus.begin(), cloneVirus.end());
			++it;
		}
		else
		{
			delete* it;
			it = this->m_virusList.erase(it);
		}
	}
		int sum = 0;
		for (it = this->m_virusList.begin(); it != this->m_virusList.end(); it++)
		{
			sum += (*it)->GetM_resistance();
		}
		cout << "Sum: " << sum << endl;
		if (this->m_resistance < sum)
		{
			this->DoDie();
		}

}

void Patient::DoDie()
{
	cout << "Patient die lol ^_^";
	this->m_state = 0;
	list<Virus *>::iterator it;
	for (it = this->m_virusList.begin(); it != this->m_virusList.end(); it++) {
		delete* it;
	}
	cout << "end game !";
}

int Patient::GetState()
{
	return this->m_state;
}

list<Virus*> Patient::getVirusList()
{
	return this->m_virusList;
}
