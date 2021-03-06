/*

Символьная строка для одного из разновидностей дампа (3 — для целочисленных (char, short, int) и 2 для вещественных (float, double) чисел) 
отправляется в текстовый файл.

Текстовый файл считывается, и его содержимое используется для инициализации массива (символьного или целочисленного), который затем распечатывается.
 
Итог: символьная строка благодаря двум посредникам для хранения её образа в виде текстового файла и массива 
возвращается обратно для просмотра в неизменном виде.
 
Для экспертизы необходимо представить программу, позволяющую построить необходимого вида дамп, записать текстовый файл, 
прочитать текстовый файл, выполнить инициализацию и визуализацию массива, а также и сам текстовый файл.
*/

#include <iostream>
using namespace std;

struct s_csi
{
	char c;
	short s;
	int i;
};

struct s_fd
{
	float f;
	double d;
};

int main()
{
	int n;
	FILE* pFile;
	struct s_csi csi;
	struct s_fd fd;

	cout << "Выберите для одного из разновидностей дампа \n\t1 - (3 — для целочисленных (char, short, int) и \n\t2. для вещественных (float, double) чисел\n";
	cout << endl;
	cin >> n;

	switch(n)
	{
		case 1:
			cout << "input char ";
			cin >> csi.c;
			cout << "input short ";
			cin >> csi.s;
			cout << "input int ";
			cin >> csi.i;

			pFile = fopen("csi.dump", "wb");
			if (!pFile)
			{
				printf("Invalid opening file!\n");
				return -1;
			}
			else
				fwrite( &csi, sizeof(csi), 1, pFile);

			fclose(pFile);

			pFile = fopen("csi.dump", "rb");
			if (!pFile)
			{
				printf("Invalid opening file!\n");
				return -1;
			}
			else
				fread( &csi, sizeof(csi), 1, pFile);

			cout << "Прочитали из файла:\n";
			cout << csi.c<<endl;
			cout << csi.s<<endl;
			cout << csi.i<<endl;

			fclose(pFile);

			break;
		case 2:
			cout << "input float ";
			cin >> fd.f;
			cout << "input double ";
			cin >> fd.d;
	
			pFile = fopen("fd.dump", "wb");
			if (!pFile)
			{
				printf("Invalid opening file!\n");
				return -1;
			}
			else
				fwrite( &fd, sizeof(fd), 1, pFile);

			fclose(pFile);

			pFile = fopen("fd.dump", "wb");
			if (!pFile)
			{
				printf("Invalid opening file!\n");
				return -1;
			}
			else
				fread( &fd, sizeof(fd), 1, pFile);

			cout << "Прочитали из файла:\n";
			cout << fd.f<<endl;
			cout << fd.d<<endl;

			fclose(pFile);

			break;
	}

	return 0;
}

