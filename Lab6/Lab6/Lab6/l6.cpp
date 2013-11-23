#include <iostream>
#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include <string.h>

using namespace std;

FILE *fl;
typedef struct
{
	char fio[30];
	unsigned char matem;
	unsigned char oaip;
} TStudent;

TStudent stud[30];
char name[20];
int nst = 0;
int Menu();
void Nnf();
void Newf();
void Spisok();
void Opf();
void Resc();
void Resf();

int main()
{
	while (true)
	{
		switch (Menu())
		{
		case 1:
			Nnf(); 
			break;
		case 2:
			Newf(); 
			break;
		case 3:
			Spisok(); 
			break;
		case 4:
			Opf(); 
			break;
		case 5:
			Resc(); 
			break;
		case 6:
			Resf(); 
			break;
		case 7:
			return 0;
		default:
			puts ("Nevernoe deystvie!");
		}
		puts ("Viberite deystvie!");
		_getch();
		system ("cls");
	}
}
int Menu()
{
	cout << "Viberite variant:" << endl;
	cout << "1.Vvod file name" << endl;
	cout << "2.New file" << endl;
	cout << "3.Vvesti spisok" << endl;
	cout << "4.Open file" << endl;
	cout << "5.Vivesti result" << endl;
	cout << "6.Vivesti file" << endl;
	cout << "7.Exit" << endl;
	int i;
	cin >> i;

	return i;
}

void Nnf()
{
	cout << "Vvedi file name" << endl;
	cin >>  name;
}

void Newf()
{
	errno_t err;
	if ((err  = fopen_s(&fl, name, "wb")) != 0)
	{ 
		cout <<"Oshibka pri sozdanii: " << err << endl;
		exit(1);
	}
	
	cout << "OK" << endl;

	fclose(fl);
}


void Spisok()
{
	errno_t err;
	if ((err  = fopen_s(&fl, name, "rb+")) != 0)
	{
		cout << "Oshibka pri sozdanii" << endl;
		exit(1);
	}
	cout << "Vvedite chislo studentov" << endl;
	cin >> nst;

	for (int i = 0; i < nst; i++)
	{
		cout << "Vvedi name: ";
		cin >> stud[i].fio;
		cout << "Vvedi ocenku po math: ";
		cin >> stud[i].matem;
		cout << "Vvod ocenki po OAIP: ";
		cin >> stud[i].oaip;

		fwrite(&stud[i], sizeof(TStudent), 1, fl);
	}
	fclose(fl);
}

void Opf()
{
	errno_t err;
	if ((err  = fopen_s(&fl, name, "rb")) != 0)
	{
		cout << "Oshibka pri otkritii" << endl;
		exit(1);
	}
	nst = 0;
	TStudent std;

	while (true)
	{
		int nwrt = fread (&std, sizeof(TStudent), 1,fl);
		if (nwrt !=1) break;

		stud[nst] = std;
		cout << stud[nst].fio << " " << stud[nst].matem << " " << stud[nst].oaip << endl;
		nst++;
	}

	fclose(fl);
}

void Resc()
{
	for (int i = 0; i < nst; i++)
	{
		if ( stud[i].oaip == '9')
		{
			cout << stud[i].fio << endl;
		}
	}
}

void Resf()
{
	char namet[30];
	FILE *ft;
	cout << "Vvedite file name" << endl;
	cin >> namet;
	errno_t err;
	if ((err  = fopen_s(&ft, namet,"w")) != 0)
	{
		cout << "Oshibka pri sozdanii" << endl;
		exit(1);
	}

	char s[80];
	for(int i = 0; i < nst; i++)
	{
		if(stud[i].oaip =='9')
		{
			strcpy_s(s, stud[i].fio);
			strcat_s(s, "\n");
			fputs(s, ft);
		}
	}
	fclose(ft);
}