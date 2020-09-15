#include <iostream>
using namespace std;

int A[100];
int matrix[100][100];

int matrixChain(int n)
{
	int j;

	for (int i = 1; i <= n; i++)
	{
		matrix[i][i] = 0;
	}

	for (int r = 1; r < n; r++)
	{
		for (int i = 1; i <= n - r; i++)
		{
			j = i + r;
			matrix[i][j] = matrix[i][i] + matrix[i + 1][j] + A[i - 1] * A[i] * A[j];

			for (int k = i; k <= j - 1; k++)
			{
				if (matrix[i][j] > matrix[i][k] + matrix[k + 1][j] + A[i - 1] * A[k] * A[j])
				{
					matrix[i][j] = matrix[i][k] + matrix[k + 1][j] + A[i - 1] * A[k] * A[j];
				}
			}
		}
	}

	return matrix[1][n];
}

int main()
{
	int n, j = 1, x;
	cin >> n;
	cin >> A[0];

	for (int i = 0; i < n * 2 - 1; i++)
	{
		cin >> x;
		if (x != A[j - 1]) A[j++] = x;
	}

	cout << matrixChain(n) << endl;

	return 0;
}