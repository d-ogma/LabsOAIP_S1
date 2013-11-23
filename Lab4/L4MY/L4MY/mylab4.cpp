#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

void GetMinIndex(int a[], int n, int *imin);
int Schetchik(int a[], int n, int *imin);

int main()
{
	int a[10], i, n, min, imin, max, imax;
	imin = 0;

	cout << "Vvedi razmer massiva: ";
	cin >> n;

	cout << "\nVvedi massive:\n";
	for (i=0; i<n; i++)
	{
		cout << "Vvedi a["<<i<<"]=";
		cin >> a[i];
	}

	cout << "\nMassive a:\n";
	for (i=0; i<n; i++)
	cout << setw(7) << a[i];
	cout << endl;

	GetMinIndex(a, n, &imin);

	int schetchik = Schetchik(a, n, &imin);
	
	cout << "\nKol-vo elementov posle min: " << schetchik << endl;
	return 0;
}

void GetMinIndex(int a[], int n, int *imin)
{
	int min = a[0];
	*imin = 0;
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min) 
		{
			min = a[i];
			*imin = i;
		}
	}
}	

int Schetchik(int a[], int n, int *imin)
{
	int schetchik = 0;

	for (int i = *imin + 1; i < n; i++)
	{
		schetchik++;
	}

	return schetchik;
}
