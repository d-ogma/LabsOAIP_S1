#include <iostream>
#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include <string.h>

using namespace std;

FILE *fl;
typedef struct
{
	char firstName[64];
	char midlleName[64];
	char lastName[64];
	double time;
	double tarif;
} TSotrudnik
	;

TSotrudnik sotr[30];
char name[20];
int nst = 0;
int Menu();
void GetFileName();
void CreateNewFile();
void Spisok();
void OpenFile();
void PokazatResult();
void VivestiResultVFile();

int main()
{
	while (true)
	{
		switch (Menu())
		{
		case 1:
			GetFileName(); 
			break;
		case 2:
			CreateNewFile(); 
			break;
		case 3:
			Spisok(); 
			break;
		case 4:
			OpenFile(); 
			break;
		case 5:
			PokazatResult(); 
			break;
		case 6:
			VivestiResultVFile(); 
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
	cout << "6.Vivesti result v file" << endl;
	cout << "7.Exit" << endl;
	int i;
	cin >> i;

	return i;
}

void GetFileName()
{
	cout << "Vvedi file name" << endl;
	cin >>  name;
}

void CreateNewFile()
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
	cout << "Vvedite chislo sotrudnikov" << endl;
	cin >> nst;

	for (int i = 0; i < nst; i++)
	{
		cout << "Vvedite imya: ";
		cin >> sotr[i].firstName;
		cout << "Vvedite otchestvo: ";
		cin >> sotr[i].midlleName;
		cout << "Vvedite familiuy: ";
		cin >> sotr[i].lastName;
		cout << "Vvedite kol-vo otrabotanyh chasov: ";
		cin >> sotr[i].time;
		cout << "Vvod pochasovoy tarif: ";
		cin >> sotr[i].tarif;

		fwrite(&sotr[i], sizeof(TSotrudnik), 1, fl);
	}
	fclose(fl);
}

void OpenFile()
{
	errno_t err;
	if ((err  = fopen_s(&fl, name, "rb")) != 0)
	{
		cout << "Oshibka pri otkritii" << endl;
		exit(1);
	}
	nst = 0;
	TSotrudnik std;

	while (true)
	{
		int nwrt = fread (&std, sizeof(TSotrudnik), 1,fl);
		if (nwrt !=1) break;

		sotr[nst] = std;
		cout << sotr[nst].firstName << " " << sotr[nst].midlleName << " " << sotr[nst].lastName << " " << sotr[nst].time << " " << sotr[nst].tarif << endl;
		nst++;
	}

	fclose(fl);
}

void PokazatResult()
{
	for (int i = 0; i < nst; i++)
	{
		cout << sotr[i].firstName << " " << sotr[i].midlleName << " " << sotr[i].lastName << " Zarplata sotrudnika: " << sotr[i].tarif * sotr[i].time << endl;
	}
}

void VivestiResultVFile()
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

	for(int i = 0; i < nst; i++)
	{
		char zp[50];
		double zpl = sotr[i].tarif * sotr[i].time;
		sprintf_s(zp, "%f", zpl);

		fputs(sotr[i].firstName, ft);
		fputs(" ", ft);
		fputs(sotr[i].midlleName, ft);
		fputs(" ", ft);
		fputs(sotr[i].lastName, ft);
		fputs(" Zarplata sotrudnika: ", ft);
		fputs(zp, ft);
		fputs("\n", ft);

	}
	fclose(ft);
}