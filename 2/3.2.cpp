#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
	ofstream fout;
	ifstream fin;
	char input[200];
	char output[200];
	int num ;

	cout << "Ввод данных\n";
        cin.getline(input , 200);

	fout.open("dump.txt");

	fout.write( input, strlen(input));
	fout << '\0';

	fout.close();

	fin.open("dump.txt");

	fin.read( output, sizeof(output));

	cout << "Прочитали из файла:\n";
	cout << output;

	fin.close();

	return 0;
}
