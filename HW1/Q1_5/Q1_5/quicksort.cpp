#include <iostream>
using namespace std;

int result_count = 0;

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int partition(int *A, int p, int r)
{
	int x = A[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++)
	{
		if (A[j] <= x)
		{
			swap(A[++i], A[j]);
			result_count++;
		}
	}
	swap(A[i + 1], A[r]);
	result_count++;

	return i + 1;
}

void quicksort(int *A, int p, int r)
{
	int q;
	if (p < r)
	{
		q = partition(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);
	}
}

int main()
{
	int n, *A;
	cin >> n;
	A = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	quicksort(A, 0, n - 1);

	cout << result_count << endl;

	return 0;

}