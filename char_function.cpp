#include <iostream>
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
	pb.b1 = 0;
	pb.b2 = 1;
	pb.b3 = 1;
	pb.b4 = 1;
	pb.b5 = 1;
	pb.b6 = 1;
	pb.b7 = 1;
	pb.b8 = 1;

	unsigned char* x;
	x = (unsigned char*)&pb ;

	cout << *x;
}

	



