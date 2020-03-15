/*

Символьная строка для одного из разновидностей дампа (3 — для целочисленных (char, short, int) и 2 для вещественных (float, double) чисел) 
отправляется в текстовый файл.

Текстовый файл считывается, и его содержимое используется для инициализации массива (символьного или целочисленного), который затем распечатывается.
 
Итог: символьная строка благодаря двум посредникам для хранения её образа в виде текстового файла и массива 
возвращается обратно для просмотра в неизменном виде.
 
Для экспертизы необходимо представить программу, позволяющую построить необходимого вида дамп, записать текстовый файл, 
прочитать текстовый файл, выполнить инициализацию и визуализацию массива, а также и сам текстовый файл.
*/

#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	FILE* pFile;
	char input[200];
	char output[200];
	int num ;

	cout << "Введите строку\n";
        fgets(input , 200, stdin);

//	cout << "Получили массив\n";
//	for(int i=0; i<200;i++)
//		cout << input[i];

	pFile = fopen("dump.txt", "wb");
	if (!pFile)
	{
		printf("Invalid opening file!\n");
		return -1;
	}
	else
		fwrite( input, strlen(input), 1, pFile);

	fclose(pFile);

	pFile = fopen("dump.txt", "rb");
	if (!pFile)
	{
		printf("Invalid opening file!\n");
		return -1;
	}
	else
		num = fread( output, 1, 200, pFile);

	output[num] = '\0';

	cout << "Прочитали из файла:\n";
	cout << output;

	fclose(pFile);


	return 0;
}
