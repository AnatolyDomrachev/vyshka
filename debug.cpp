// C++ Function templates
// Pack binary dump into array
#include <iostream>
using namespace std;

void binaryDump(short int n, int* p)
{
	cout << "\n#FUNCTION binaryDump(short int n, int* p)\n";

	short int mask(040000);

	cout << "#	Теперь mask = 040000"<< endl;

	p[15] = n < 0 ? 1 : 0;

	cout << "#	Теперь p[15] = " << (n < 0 ? 1 : 0) << endl;

	// 15
	for (int i = 0; i < 15; ++i, mask >>= 1)
	{
		p[15-i-1] = n & mask ? 1 : 0;

		cout << "#	Теперь p["<< 15-i-1 << "] = " << (n < 0 ? 1 : 0) << endl;
	}

	// 14 - 0
	cout << "\n# END FUNCTION binaryDump(short int n, int* p)\n\n";
}

template <typename T>
void print(int* p)
{
	cout << "\n#FUNCTION print(int* p)\n";

	int size(8 * sizeof(T));

	cout << "#	Теперь size = " << sizeof(T) << endl;

	cout << "#	Вывод p[size-i-1] в при (int i = 0; i < size; ++i) " << endl;

	for (int i = 0; i < size; ++i)
		cout << p[size-i-1];
	cout << endl;
	// 31 - 0 or 63 - 0

	cout << "\n# END FUNCTION print(int* p)\n\n";
}

template <typename T>
void printFields(int* p)
{
	cout << "#FUNCTION printFields(int* p)\n";

	int size(8 * sizeof(T));

	cout << "#	Теперь size = " << 8 * sizeof(T) << endl;

	// binary fields S, E, M

	cout << "#	Вывод (p[size-1] < 0 ? 1 : 0) " << endl;

	cout << ( p[size-1] < 0 ? 1 : 0) ; // 31 or 63
	switch (sizeof(T))
	{
		case 4 :

			cout << "#	Вывод p[size-1-i-1] при  (int i = 0; i < 8; ++i)" << endl;

			cout << ' ';

			for (int i = 0; i < 8; ++i) // 30 - 23
				cout << p[size-1-i-1];

			cout << "#	Вывод p[size-8-i-2] при  (int i = 0; i < 23; ++i)" << endl;

			cout << ' ';

			for (int i = 0; i < 23; ++i) // 22 - 0
				cout << p[size-8-i-2];

			break;
		case 8 :

			cout << "#	Вывод p[size-1-i-1] при (int i = 0; i < 11; ++i)" << endl;

			cout << ' ';

			for (int i = 0; i < 11; ++i) // 62 - 52
				cout << p[size-1-i-1];

			cout << "#	Вывод p[size-11-i-2] при (int i = 0; i < 52; ++i)" << endl;

			cout << ' ';

			for (int i = 0; i < 52; ++i) // 51 - 0
				cout << p[size-11-i-2];
		break;
	}

	cout << endl;

	cout << "# END FUNCTION printFields(int* p)\n\n";
}

template <typename T>
void pack(T* pFloat, int* p)
{
	cout << "\n#FUNCTION pack(T* pFloat, int* p)\n";

	short int* pShort = reinterpret_cast<short int*>(pFloat);

	cout << "#	Теперь pShort это массив из 64 элементов типа short int, которые находятся в той же области памяти, где находится массив p  "<< endl;


	int size(sizeof(T) / sizeof(short int));

	cout << "#	Теперь size = " << sizeof(T) << "/" << sizeof(short int) << "=" << size << endl;

	int index;
	for (int i = 0; i < size; ++i)
	{
		index = size - i - 1;

		cout << "#	Теперь index = " << size - i - 1<< endl;
		cout << "#	Вызов функции binaryDump(pShort[index], p + 16 * index);"<< endl;

		binaryDump(pShort[index], p + 16 * index);

	}

	cout << "\n# END FUNCTION pack(T* pFloat, int* p)\n\n";
}

int main()
{
	cout << "#FUNCTION MAIN  \n";

	int* p; // указатель, указывает на область памяти, в которой хранится число типа int
	float f(-1.0);

	cout << "#	Теперь f = " << f<< endl;

	p = new int[8*sizeof(float)]; 

	cout << "#	Теперь p это массив из 32 элементов int"<< endl;
	cout << "#	Вызов функции pack<float>(&f, p);"<< endl;

	pack<float>(&f, p);
	/*
	 <float> - тип данных, который в функции pack будет обозначен буквой T
	&f - значит что фунлция pack сможет изменять значение f и оно изменится в функции main
	 */

	cout << "#	Вызов функции print<float>(p);"<< endl;
	print<float>(p);

	cout << "#	Вызов функции printFields<float>(p);"<< endl;

	printFields<float>(p);
	delete[] p;
	cout << endl;

	double d(-1.0);

	cout << "#	Теперь d = " << d<< endl;

	p = new int[8*sizeof(double)];

	cout << "#	Теперь p это массив из 64 элементов int "<< endl;
	cout << "#	Вызов функции pack<float>(&d, p);"<< endl;

	pack<double>(&d, p);

	cout << "#	Вызов функции print<double>(p);"<< endl;

	print<double>(p);

	cout << "#	Вызов функции printFields<double>(p);"<< endl;

	printFields<double>(p);
	delete[] p;
	return 0;

	cout << "# END FUNCTION MAIN  \n\n";
}
