#pragma once
#include "Virus.h"
#include "list"
using namespace std;
class FluVirus : Virus
{
private:
	int m_color;
public:
	FluVirus();
	~FluVirus();
	void SetM_color(int);
	int GetM_color();
	void DoBorn();
	list<Virus *> DoClone();
	void DoDie();
	void InitResistance();


};

