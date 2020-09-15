#include <iostream>
#include <algorithm>

using namespace std;

int MaxPeb(int** peb, int n)
{
	int result = peb[0][n];

	for (int i = 1; i < 4; i++)
	{
		if (result <= peb[1][n])
			result = peb[1][n];
	}

	return result;

}

int compatible(int** peb, int n, int p)
{
	int result = 0;

	switch (p)
	{
		case 0:
			result = max(peb[1][n], peb[2][n]);
			break;
		case 1:
			result = max(max(peb[0][n], peb[2][n]), peb[3][n]);
			break;
		case 2:
			result = max(peb[0][n], peb[1][n]);
			break;
		case 3:
			result = peb[1][n];
			break;
	}

	return result;
}

int pebble(int** peb, int n, int p)
{
	int result = -1;

	switch (p)
	{
		case 0:
			result = peb[0][n];
			break;
		case 1:
			result = peb[1][n];
			break;
		case 2:
			result = peb[2][n];
			break;
		case 3:
			result = peb[0][n] + peb[2][n];
			break;
	}

	return result;
}

int pebbleSum(int** peb, int n)
{
	int** sum;
	int result;
	sum = new int* [4];
	for (int i = 0; i < 4; i++)
		* (sum + i) = new int[n];

	for (int p = 0; p < 4; p++)
		sum[p][0] = pebble(peb, 0, p);
	for (int i = 1; i < n; i++)
	{
		for (int p = 0; p < 4; p++)
			sum[p][i] = pebble(peb, i, p) + compatible(sum, i - 1, p);

	}
	result = MaxPeb(sum, n - 1);

	for (int i = 0; i < 4; i++)
		delete[] * (sum + i);

	delete[]sum;
	

	return result;
}

int main()
{
	int m, maxi;
	int** p;
	cin >> m;

	p = new int* [3];
	for (int i = 0; i < 3; i++)
		* (p + i) = new int[m];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> p[i][j];
	}

	maxi = pebbleSum(p, m);
	cout << maxi << endl;

	for (int i = 0; i < 3; i++)
		delete[] * (p + i);

	delete[]p;

	return 0;
}