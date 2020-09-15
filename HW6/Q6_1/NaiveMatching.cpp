#include <iostream>
#include <string>
using namespace std;

int match_count = 0;
int compare_count = 0;

bool isMatching(string A, string P, int index)
{
	int m = P.length();

	for (int i = 0; i < m; i++)
	{
		compare_count++;
		if (P[i] != A[i + index]) return false;
	}

	return true;
}

void naiveMatching(string A, string P)
{
	int n = A.length();
	int m = P.length();
	bool match = false;

	for (int i = 0; i < n - m + 1; i++)
	{
		match = isMatching(A, P, i);

		if (match == true) match_count++;
	}
}

int main()
{
	string a, b;

	getline(cin, a);
	getline(cin, b);

	naiveMatching(a, b);

	cout << compare_count << " " << match_count << endl;

	return 0;
}