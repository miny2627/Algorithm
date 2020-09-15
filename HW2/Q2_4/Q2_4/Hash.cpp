#include <iostream>
using namespace std;

int col = 0;
int hashtable[1000] = { 0 };

void h_i(int a, int x)
{
	if (hashtable[a] == NULL)
		hashtable[a] = x;
	else
	{
		h_i(a + 1, x);
		col++;
	}
}

int main()
{
	int n, m, a, p = 0;
	cin >> n;

	m = 2 * n;

	while (1)
	{
		for (int i = 2; i < n; i++)
		{
			if (m % i == 0)
			{
				m++;
				p++;
				break;
			}
		}
		if (p == 0) break;

		p = 0;
	}
	
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		h_i(a % m, a);
	}

	cout << col << endl;

	return 0;
}