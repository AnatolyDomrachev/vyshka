// C++ Function templates
// Pack binary dump into array
#include <iostream>
using namespace std;

void binaryDump(short int n, int* p)
{
	short int mask(040000);
	p[15] = n < 0 ? 1 : 0;
	// 15
	for (int i = 0; i < 15; ++i, mask >>= 1)
	p[15-i-1] = n & mask ? 1 : 0;
	// 14 - 0
}

template <typename T>
void print(int* p)
{
	int size(8 * sizeof(T));
	for (int i = 0; i < size; ++i)
	cout << p[size-i-1];
	cout << endl;
	// 31 - 0 or 63 - 0
}

template <typename T>
void printFields(int* p)
{
	int size(8 * sizeof(T));
	// binary fields S, E, M
	cout << ( p[size-1] < 0 ? 1 : 0) ; // 31 or 63
	switch (sizeof(T))
	{
	case 4 :
	cout << ' ';
	for (int i = 0; i < 8; ++i) // 30 - 23
	cout << p[size-1-i-1];
	cout << ' ';
	for (int i = 0; i < 23; ++i) // 22 - 0
	cout << p[size-8-i-2];
	break;
	case 8 :
	cout << ' ';
	for (int i = 0; i < 11; ++i) // 62 - 52
	cout << p[size-1-i-1];
	cout << ' ';
	for (int i = 0; i < 52; ++i) // 51 - 0cout << p[size-11-i-2];
	break;
}

cout << endl;

}

template <typename T>
void pack(T* pFloat, int* p)
{
	short int* pShort = reinterpret_cast<short int*>(pFloat);
	int size(sizeof(T) / sizeof(short int));
	int index;
	for (int i = 0; i < size; ++i)
	{
		index = size - i - 1;
		binaryDump(pShort[index], p + 16 * index);
	}
}

int main()
{
	int* p; // указатель, указывает на область памяти, в которой хранится число типа int
	float f(-1.0);

	p = new int[8*sizeof(float)]; 
	/*
	   В норме должно быть так
	p = new int[8*sizeof(int)]; 
	но это не важно так как размер у них одинаковый

	Это выделяется память для массива int из 8 элементов
	 */

	pack<float>(&f, p);
	/*
	 <float> - тип данных, который в функции pack будет обозначен буквой T
	&f - значит что фунлция pack сможет изменять значение f и оно изменится в функции main
	 */

	print<float>(p);
	printFields<float>(p);
	delete[] p;
	cout << endl;
	double d(-1.0);
	p = new int[8*sizeof(double)];
	pack<double>(&d, p);
	print<double>(p);
	printFields<double>(p);
	delete[] p;
	return 0;
}
