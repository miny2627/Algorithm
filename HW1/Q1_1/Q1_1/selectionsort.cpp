#include <iostream>
using namespace std;

int result_count = 0;

int selection_sort(int *A, int n)
{
	if (n == 1) return result_count;
	int max = 0;
	for (int i = 1; i < n; i++)
	{
		if (A[max] < A[i])
		{
			max = i;
			result_count++;
		}
	}
	swap(A[max], A[n - 1]);
	return selection_sort(A, n - 1);
}

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
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

	cout << selection_sort(A, n) << endl;

	return 0;
}