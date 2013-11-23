#include <iostream>;
#include <iomanip>;
#include <math.h>;

using namespace std;

double Proizvedenie(double **a, int n, int m);

int main()
{
	double **a, tmp;
	int i, n, m, imin, jmin, imax, jmax;

	cout << "Vvedi razmer massiva A:\n";
	cout << "row n=";
	cin >> n;
	cout << "column m=";
	cin >> m;
	
	if (n != m)
	{
		cout << "Glavnaya diag otsutstvuet" << endl;
		exit(1);
	}

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

	double proizvedenie = Proizvedenie(a, n, m);

		cout << "\nResult proizvedeniya elementov nije glavnoy diag: " << proizvedenie << endl;
	
	for (int i = 0; i < n; i++)
	{
		delete [] a[i];
	}
	
	delete []a;
	a = NULL;
	
	return 0;
}

double Proizvedenie(double **a, int n, int m)
{

	double proizvedenie = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			proizvedenie*=a[i][j-1];
		}
	}
	return proizvedenie;
}



