#include <iostream>
using namespace std;

int matrixPath(int **tmp, int **matrix, int n, int m)
{	
	matrix[1][1] = tmp[1][1];

	for (int i = 2; i <= n; i++)
	{
		matrix[i][1] = tmp[i][1] + matrix[i - 1][1];
	}
	for (int j = 2; j <= m; j++)
	{
		matrix[1][j] = tmp[1][j] + matrix[1][j - 1];
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= m; j++)
		{
			if (matrix[i - 1][j] > matrix[i][j - 1])
			{
				matrix[i][j] = tmp[i][j] + matrix[i][j - 1];
			}
			else
				matrix[i][j] = tmp[i][j] + matrix[i - 1][j];
		}
	}
	return matrix[n][m];
}

int main()
{
	int n, m;
	int** tmp = NULL, ** matrix = NULL;
	
	cin >> n >> m;
	
	tmp = new int* [n + 1];
	matrix = new int* [n + 1];

	for (int i = 1; i <= n; i++)
	{
		tmp[i] = new int[m + 1];
		matrix[i] = new int[m + 1];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			matrix[i][j] = 0;
			cin >> tmp[i][j];
		}
	}

	cout << matrixPath(tmp, matrix, n, m) << endl;

	for (int i = 1; i <= m; i++)
	{
		delete tmp[i];
		delete matrix[i];
	}
	delete(tmp);
	delete(matrix);

	return 0;
}