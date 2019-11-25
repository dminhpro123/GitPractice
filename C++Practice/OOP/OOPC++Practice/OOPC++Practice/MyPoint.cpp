#include <iostream>
#include <math.h>
#include "MyPoint.h"


using namespace std;

MyPoint::MyPoint()
{
}

MyPoint::MyPoint(int mPosX, int mPosY)
{
	this->mPosX = mPosX;
	this->mPosY = mPosY;
}

void MyPoint::Display()
{
	cout << "Pos X: " << mPosX << endl;
	cout << "Pos Y: " << mPosY << endl;
}

void MyPoint::SetX(int mPosX)
{
	this->mPosX = mPosX;
}

int MyPoint::GetX()
{
	return mPosX;
}

void MyPoint::SetY(int mPosY)
{
	this->mPosY = mPosX;
}

int MyPoint::GetY()
{
	return mPosY;
}

float MyPoint::Distance(MyPoint p)
{
	return sqrt((this->GetX() - p.GetX()) * (this->GetX() - p.GetX()) + (this->GetY() - p.GetY()) * (this->GetY() - p.GetY()));
}
