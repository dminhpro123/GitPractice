#pragma once
#include "Virus.h"
#include "list"
using namespace std;
class FluVirus : public Virus
{
private:
	int m_color;
public:
	FluVirus();
	~FluVirus();
	FluVirus(const FluVirus&);
	void SetM_color(int);
	int GetM_color();
	void DoBorn();
	list<Virus *> DoClone();
	void DoDie();
	void InitResistance();


};

