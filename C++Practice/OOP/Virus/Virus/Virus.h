#pragma once
#include "list"
using namespace std;

class Virus
{
private:
	char* m_dna;
	int m_resistance;
public:
	Virus();
	Virus(char*, int);
	~Virus();
	Virus(const Virus &Virus);
	void SetM_dna(char*);
	char* GetM_dna();
	void SetM_resistance(int);
	int GetM_resistance();
	void LoadADNInformation();
	void ReduceResistance(int);
	virtual void DoBorn() = 0;
	virtual list<Virus *> DoClone() = 0;
	virtual void DoDie() = 0;
	virtual void InitResistance() = 0;

};