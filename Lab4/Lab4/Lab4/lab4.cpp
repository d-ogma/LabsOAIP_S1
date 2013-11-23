#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

void MinMax (int a[], int n, int *min, int *max, int *imin, int *imax);

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

	MinMax (a, n, &min, &max, &imin, &imax);
	
	cout << "\nMax=" << max << setw(10) << "i=" << imax;
	cout << "\nMin=" << min << setw(11) << "i=" << imin << endl;
	getchar();
	return 0;
}

void MinMax (int a[], int n, int *min, int *max, int *imin, int *imax)
{
	*min = a[0];
	*max= a[0];
	*imin = 0;
	*imax = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < *min) 
		{
			*min = a[i];
			*imin = i;
		}
		else if (a[i] > *max)
		{
			*max=a[i];
			*imax=i;
		}
	}
}	