#include <iostream>
using namespace std;

int result_count = 0;

void heapify(int *A, int k, int n)
{
	int left, right;
	left = 2 * k;
	right = 2 * k + 1;
	int big, tmp;

	if (right <= n)
	{
		if (A[right] >= A[left])
		{
			big = right;
		}
		else
			big = left;
	}
	else if (left <= n) big = left;
	else
		return;

	if (A[big] > A[k])
	{
		tmp = A[k];
		A[k] = A[big];
		A[big] = tmp;

		heapify(A, big, n);
		result_count++;
	}
}

void build_heap(int *A, int n)
{
	for (int i = n / 2; i > 0; i--)
	{
		heapify(A, i, n);
	}
}

void heapsort(int *A, int n)
{
	int tmp;
	build_heap(A, n);
	result_count = 0;

	for (int i = n; i > 1; i--)
	{
		tmp = A[1];
		A[1] = A[i];
		A[i] = tmp;

		heapify(A, 1, i - 1);
	}
}

int main()
{
	int n, *A;
	cin >> n;
	A = new int[n+1];

	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
	}

	heapsort(A, n);

	cout << result_count << endl;

	return 0;
}