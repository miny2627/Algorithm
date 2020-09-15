#include <iostream>
#include <cmath>
using namespace std;

int A[10000];

int getMax(int n)
{
	int max = A[0];
	for (int i = 1; i < n; i++)
	{
		if (max < A[i]) max = A[i];
	}
	return log10((double)max)+1;
}

int digit(int val, int t)
{
	return (val % (int)pow(10.0, t)) / pow(10.0, t - 1); //num that digit is t
}

void radixsort(int n, int t)
{
	int k = getMax(n); //max digit
	int *output = new int[n];
	int count[10] = { 0 };
	int d;

	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			d = digit(A[j], i);
			count[d]++;
		}
		for (int j = 1; j < 10; j++)
			count[j] += count[j - 1];
		for (int j = n - 1; j >= 0; j--)
		{
			d = digit(A[j], i);
			output[count[d] - 1] = A[j];
			count[d]--;
		}
		for (int j = 0; j < n; j++)
			A[j] = output[j];

		if (i == t) break;
		else
		{
			for (int i = 0; i < 10; i++)
				count[i] = 0;
		}
	}
}

int main()
{
	int n, t;
	cin >> n >> t;

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	radixsort(n, t);

	for (int i = 0; i < n; i++)
		cout << A[i] << " ";

	return 0;
}
