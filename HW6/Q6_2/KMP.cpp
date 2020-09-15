#include <iostream>
#include <cstring>
using namespace std;

int pi[100];
int compare_count = 0;
int fail = 0;

void preprocessing(char* P)
{
	int j = 0;
	int k = -1;
	pi[0] = -1;
	int m = strlen(P);

	while (j < m)
	{
		if (k == -1 || P[j] == P[k])
		{
			j++;
			k++;
			pi[j] = k;
		}
		else
			k = pi[k];
	}
}

void KMP(char* A, char* P)
{
	preprocessing(P);
	int i = 0, j = 0;
	int n = strlen(A);
	int m = strlen(P);

	while (i < n)
	{
		compare_count++;
		if (j == -1 || A[i] == P[j])
		{
			i++;
			j++;
		}
		else
			j = pi[j];

		if (j == m)
		{
			fail = 1;
			cout << compare_count << endl;
			j = pi[j];
		}
	}
	if (fail == 0) cout << "fail" << endl;

}

int main()
{
	char a[1000], b[100];
	cin >> a >> b;
	KMP(a, b);

	return 0;
}