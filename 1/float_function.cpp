#include "stdio.h"
#include <iostream>
using namespace std;

int main()
{
#pragma pack(push, 1)
	struct byte
	{
		unsigned b1:1;
		unsigned b2:1;
		unsigned b3:1;
		unsigned b4:1;
		unsigned b5:1;
		unsigned b6:1;
		unsigned b7:1;
		unsigned b8:1;
	};
#pragma pack(pop)

	int p[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,0,0};
	//int p[] = {1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	//int p[] = {0,0,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


	struct byte pb[4];

	for( int i=0; i<4 ; i++ )
	{
		pb[i].b1 = p[(i)*8];
		pb[i].b2 = p[(i)*8+1];
		pb[i].b3 = p[(i)*8+2];
		pb[i].b4 = p[(i)*8+3];
		pb[i].b5 = p[(i)*8+4];
		pb[i].b6 = p[(i)*8+5];
		pb[i].b7 = p[(i)*8+6];
		pb[i].b8 = p[(i)*8+7];
	}

	float* x = (float*)pb ;
	//cout.precision(8);
	cout << "x = " << *x << endl;
	//printf("%.1f\n", *x);

	return 0;
}

		/*
		pb[i].b1 = p[(3-i)*8+7];
		pb[i].b2 = p[(3-i)*8+6];
		pb[i].b3 = p[(3-i)*8+5];
		pb[i].b4 = p[(3-i)*8+4];
		pb[i].b5 = p[(3-i)*8+3];
		pb[i].b6 = p[(3-i)*8+2];
		pb[i].b7 = p[(3-i)*8+1];
		pb[i].b8 = p[(3-i)*8];
		*/
