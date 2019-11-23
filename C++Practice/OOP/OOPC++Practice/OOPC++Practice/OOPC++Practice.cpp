#include <iostream>
#include <string>
#include "MyPoint.h"

using namespace std;

void main()
{
	MyPoint mP1 = MyPoint(2, 3);
	mP1.Display();
	MyPoint mP2 = MyPoint(4, 3);
	mP2.Display();
	cout << mP1.Distance(mP2);
}