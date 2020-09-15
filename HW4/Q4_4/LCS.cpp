#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int C[100][100];
char A[100];
char B[100];

int LCS(int m, int n)
{
	for (int i = 0; i <= m; i++)
	{
		C[i][0] = 0;
	}
	
	for (int j = 0; j <= n; j++)
	{
		C[0][j] = 0;
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (A[i - 1] == B[j - 1])
				C[i][j] = C[i - 1][j - 1] + 1;
			else
				C[i][j] = max(C[i - 1][j], C[i][j - 1]);
		}
	}

	return C[m][n];
}

int main()
{
	int m, n, result = 0;
	cin >> A >> B;

	m = strlen(A);
	n = strlen(B);

	result = LCS(m, n);

	cout << result << endl;

	return 0;
}