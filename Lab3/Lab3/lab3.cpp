#include <iostream>
#include <math.h>
#include <iomanip>
#include <conio.h>

using namespace std; 

double Summa (double, int);
void Summa (double*,int*,double*);
void Summa (double&,int&,double&);

double sumValue;

int main()
{	
	double rangeMin, rangeMax, increment;
    int numberOfIteration;

	// Zaprashivaem u polzovatelya neobhodimye vhodnye dannye. Zapisyvaem ih v sootvetstvujuschie peremennye.
	cout << "Vvedite a: ";
	cin >> rangeMin;

	cout << "Vvedite b: ";
	cin >> rangeMax;

	cout << "Vvedite h: ";
	cin >> increment;
	
	cout << "Vvedite k: ";
	cin >> numberOfIteration;
	
	// Initsializiruem peremennye hranyaschie summy
	sumValue = 0;
	double sumPointer = 0;
	double sumRef = 0;

	// Vyvodim zagolovok
	cout << "\n" << setw(15) << "Value" << setw(27) << "Pointer" << setw(28) << "Reference\n";
	cout << "---------------------------------------------------------------------------------" << endl;
	
	// Prisvaivaem znacheniju x znachenie nizhnego diapazona i zapuskaem tsykl.
	double x = rangeMin;
	do
	{
		// Vyvodim rezultat funktsii poluchivshey argumenty po znacheniju
		cout << setw(10) << x << setw(15) << Summa(x, numberOfIteration);

		// Vyvodim rezultat funktsii poluchivshey argumenty po ukazatelu
		Summa(&x, &numberOfIteration, &sumPointer);
		cout << setw(10) << x << setw(15) << sumPointer;
	
		// Vyvodim rezultat funktsii poluchivshey argumenty po ssylke
		Summa(x, numberOfIteration, sumRef);
		cout << setw(10) << x << setw(15) << sumRef << endl;

		// Uvelichivaem znachenie x na zadannyi shag
		x += increment;
	
	} while (x <= rangeMax + increment / 2);
	
	// Vyvodim podcherkivanie
	cout << "---------------------------------------------------------------------------------" << endl;
	
	return 0;
}

double Summa (double x, int numberIteration)
{
	for (int i = 1; i <= numberIteration; i++)
	{
		sumValue += ((pow(double(numberIteration), 2) + 1) / numberIteration) * (pow((x / 2), numberIteration));
	}
	return sumValue;
}

void Summa (double *x, int *numberIteration, double *sum)
{
	for (int i = 1; i <= *numberIteration; i++)
	{
		*sum += ((pow(double(*numberIteration), 2) + 1) / (*numberIteration)) * (pow((*x / 2), *numberIteration));
	}
}

void Summa (double &x, int &numberIteration, double &sum)
{
	for (int i = 1; i <= numberIteration; i++)
	{
		sum += ((pow(double(numberIteration), 2) + 1) / numberIteration) * (pow(( x / 2), numberIteration));
	}
}

	
	