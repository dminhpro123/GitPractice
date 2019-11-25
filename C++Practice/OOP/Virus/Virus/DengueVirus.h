#pragma once
#include "Virus.h"
#include "list"

using namespace std;

class DengueVirus : Virus
{
private:
	char m_protein[4];
public:
	DengueVirus();
	~DengueVirus();
	void GetM_protein(char *);
	char* SetM_protein();
	void DoBorn();
	list <Virus *> DoClone();
	void DoDie();
	void InitResistance();

};
