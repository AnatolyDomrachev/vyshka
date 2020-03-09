#include <iostream>
#include "stdio.h"

using namespace std;

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

int main()
{
	struct byte pb;
	pb.b1 = 1;
	pb.b2 = 1;
	pb.b3 = 0;
	pb.b4 = 0;
	pb.b5 = 0;
	pb.b6 = 0;
	pb.b7 = 0;
	pb.b8 = 0;

	unsigned char* x;
	x = (unsigned char*)&pb ;//теперь компилятор считает, что в памяти по адресу &pb находится unsigned char

	//cout << *x;
	printf("%d \n", *x);
}

	



