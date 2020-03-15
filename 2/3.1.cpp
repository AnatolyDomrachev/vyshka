#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	FILE* pFile;
	char input[100][20];
	char output[100][20];
	int num ;

	cout << "Введите данные. по оокнчании ввода нажмите Ctrl+d в пустой строке\n";
	int i = 0;
	while(cin >> input[i])
		i++;

	pFile = fopen("dump.txt", "wb");
	if (!pFile)
	{
		printf("Invalid opening file!\n");
		return -1;
	}
	else
		fwrite( input, sizeof(input[0]), i, pFile);

	fclose(pFile);

	pFile = fopen("dump.txt", "rb");
	if (!pFile)
	{
		printf("Invalid opening file!\n");
		return -1;
	}
	else
		num = fread( output, sizeof(input[0]), i, pFile);

	cout << "Прочитали из файла:\n";

	for(int j=0; j<i;j++)
		cout << output[j] << " ";

	fclose(pFile);


	return 0;
}
