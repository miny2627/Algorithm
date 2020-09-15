#include <iostream>
using namespace std;

int rcount = 0;

void merge(int *A, int low, int mid, int high)
{
	int i, j, t;
	int *tmp = new int[high - low + 1];
	i = low;
	j = mid + 1;
	t = 0;

	while (i <= mid && j <= high)
	{
		if (A[i] < A[j]) 
			tmp[t++] = A[i++];
		else
			tmp[t++] = A[j++];

		rcount++;
	}

	while (i <= mid)
		tmp[t++] = A[i++];

	while (j <= high)
		tmp[t++] = A[j++];

	i = low;
	t = 0;

	while (i <= high)
		A[i++] = tmp[t++];
}

void mergesort(int *A, int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = (low + high) / 2;
		mergesort(A, low, mid);
		mergesort(A, mid + 1, high);
		merge(A, low, mid, high);
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

	mergesort(A, 0, n - 1);

	cout << rcount << endl;

	return 0;
}