#include <iostream>
#define INF 1e9
using namespace std;

int extractMin(int* d, bool* visited, int n)
{
	int min = INF;
	int u = 0;

	for (int i = 1; i <= n; i++)
	{
		if (d[i] < min && !visited[i])
		{
			min = d[i];
			u = i;
		}
	}

	return u;
}

int main()
{
	int n, m;
	int r, t, u;
	int v, e, w;
	cin >> n >> m;

	int* d = new int[n + 1];
	int** adj = new int*[n + 1];
	int* prev = new int[n + 1];
	bool* visited = new bool[n + 1];

	for (int i = 1; i <= n; i++)
	{
		d[i] = INF;
		prev[i] = NULL;
		visited[i] = false;
		adj[i] = new int[n + 1];
		for (int j = 1; j <= n; j++)
		{
			adj[i][j] = INF;
		}
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> v >> e >> w;
		adj[v][e] = w;
	}

	cin >> r >> t;

	d[r] = 0;

	for (int i = 1; i <= n - 2; i++)
	{
		u = extractMin(d, visited, n);
		visited[u] = true;

		for (int j = 1; j <= n; j++)
		{
			if (adj[u][j]!=INF)
			{
				if (!visited[j] && (d[u] + adj[u][j] < d[j]))
				{
					d[j] = d[u] + adj[u][j];
					prev[j] = u;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << prev[i] << " ";
	}

	if (d[t] == INF)
	{
		cout << "Impossible" << endl;
	}
	else
		cout << d[t] << endl;

	delete[]prev;
	delete[]d;
	delete[]visited;
	for (int i = 1; i <= n; i++)
	{
		delete[]adj[i];
	}
	delete[]adj;

	return 0;

}