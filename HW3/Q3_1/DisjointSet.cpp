#include <iostream>
#define MAX_SIZE 30000
using namespace std;

int parent[MAX_SIZE] = { 0 };
int Rank[MAX_SIZE] = { 0 };

void make_set(int x)
{
	parent[x] = x;
}
int find(int x)
{
	if (x == parent[x])
		return parent[x];
	else
	{
		int y = find(parent[x]);
		return y;
	}
}

void union_set(int x, int y)
{
	int xr = find(x);
	int yr = find(y);

	if (xr != yr)
	{
		parent[yr] = xr;
	}
}

int main()
{
	int n, m, x, y;
	int max = 0;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		make_set(i);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		union_set(x, y);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (find(i) == find(j))
				Rank[i]++;
		}
	}

	max = Rank[1];
	for (int i = 1; i <= n; i++)
	{
		if (max < Rank[i])
			max = Rank[i];
	}
	cout << max << endl;

	return 0;
}