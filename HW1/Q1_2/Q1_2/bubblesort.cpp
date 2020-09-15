#include <iostream>
using namespace std;

int result_count = 0;

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int bubblesort(int *A, int n)
{
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (A[j] > A[j + 1])
			{
				swap(A[j], A[j + 1]);
				result_count++;
			}
		}
	}

	return result_count;
}

int main()
{
	int n;
	int *A;
	cin >> n;
	A = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	cout << bubblesort(A, n) << endl;

	return 0;
}
