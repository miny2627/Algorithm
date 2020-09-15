#include <iostream>
#include <string>
using namespace std;

int jump[1000];
int rcount = 0;
int match = 0;

void computeJump(string P, int* ju)
{
	int m = P.length();
	for (int i = 0; i < 50; i++)
	{
		ju[i] = m;
	}

	for (int i = 0, j = m - 1; i < m - 1; i++, j--)
	{
		ju[P.at(i) - 97] = j;
	}
	ju[P.at(m - 1) - 97] = m;
}

void BoyerMooreHorspool(string A, string P)
{
	computeJump(P, jump);
	int i = 0, j = 0, k = 0;
	int n = A.length();
	int m = P.length();

	while (i < n - m + 1)
	{
		j = m - 1;
		k = i + m - 1;
		while (j >= 0 && P.at(j) - 97 == A.at(k) - 97)
		{
			rcount++;
			j--;
			k--;
		}
		if (j < 0) match++;

		i = i + jump[A.at(i + m - 1) - 97];
	}
}

int main()
{
	string a, b;
	getline(cin, a);
	getline(cin, b);
	
	BoyerMooreHorspool(a, b);
	cout << rcount << " " << match << endl;

	return 0;
}