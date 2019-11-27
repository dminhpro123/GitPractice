#pragma once
#include "Virus.h"
#include "list"

using namespace std;

class DengueVirus : public Virus
{
private:
	char* m_protein;
public:
	DengueVirus();
	~DengueVirus();
	DengueVirus(const DengueVirus&);
	void SetM_protein(char *);
	char* GetM_protein();
	void DoBorn();
	list <Virus *> DoClone();
	void DoDie();
	void InitResistance();

};
