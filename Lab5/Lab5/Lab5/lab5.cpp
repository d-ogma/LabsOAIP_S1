#include <iostream>;
#include <iomanip>;
#include <math.h>;

using namespace std;

void Poisk (double **a, int n, int m, int *imin, int *imax, int*jmin, int *jmax);

int main()
{
	double **a, tmp;
	int i, n, m, imin, jmin, imax, jmax;

	cout << "Vvedi razmer massiva A:\n";
	cout << "row n=";
	cin >> n;
	cout << "column m=";
	cin >> m;
	
	a = new double*[n];
	for (i=0; i<n; i++)
	{
		a[i] = new double[m];
	}
	
	cout << "\nVvedi massiv A:\n";
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			cout << "Vvedi a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
	}

	cout << "\nMassiv A:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(9) << a[i][j];
		}
		cout << endl; 
	}

	Poisk (a, n, m, &imin, &imax, &jmin, &jmax);

	tmp = a[imin][jmin];
	a[imin][jmin] = a[imax][jmax];
	a[imax][jmax] = tmp;

	cout << "\nResult massiv:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(9) << a[i][j];
		}
		cout << endl;
	} 

	for (int i = 0; i < n; i++)
	{
		delete [] a[i];
	}
	
	delete []a;
	a = NULL;
	int h = 0;
	cin >> h;
	return 0;
}
	void Poisk (double **a, int n, int m, int *imin, int *imax, int*jmin, int *jmax)
	{

		*imin = *jmin = *imax = *jmax = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] < a[*imin][*jmin])
				{
					*imin = i;
					*jmin = j;
				}
				if (a[i][j] > a[*imax][*jmax])
				{
					*imax = i;
					*jmax = j;
				}
			}
		}
	}



