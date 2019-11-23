#pragma once

class MyPoint
{

private:
	int mPosX;
	int mPosY;
public:
	MyPoint();
	MyPoint(int, int);
	void Display();
	void SetX(int);
	int GetX();
	void SetY(int);
	int GetY();
	float Distance(MyPoint);// : return distance between current point and p


};

