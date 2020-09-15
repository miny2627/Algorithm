#include <iostream>
using namespace std;

void countingsort(int *A, int *B, int n)
{
	int max = A[0], min = A[0];
	for (int i = 0; i < n; i++)
	{
		if (max < A[i]) max = A[i];
		if (min > A[i]) min = A[i];
	}

	int k = max - min + 1;
	int *C = new int[k];

	for (int i = 0; i < k; i++)
	{
		C[i] = 0;
	}

	for (int j = 0; j < n; j++)
	{
		C[A[j] - min]++;
	}

	for (int i = 1; i < k; i++)
	{
		C[i] = C[i] + C[i - 1];
	}

	//for (int j = n - 1; j >= 0; j++)
	//{
	//	B[C[A[j] - min]] = A[j];
	//	C[A[j] - min]--;
	//}

	for (int i = 0; i < k; i++)
	{
		cout << C[i] << " ";
	}
	cout << endl;
}

int main()
{
	int n, *A, *B;
	cin >> n;
	A = new int[n];
	B = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
		B[i] = 0;
	}

	countingsort(A, B, n);

	return 0;
}