#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

void BFS(int s, vector<int>* v, bool* visited)
{
	queue<int> q;

	q.push(s);
	visited[s] = true;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		cout << u << " ";

		for (int i = 0; i < v[u].size(); i++)
		{
			if (visited[v[u][i]] == false)
			{
				q.push(v[u][i]);
				visited[v[u][i]] = true;
			}
		}

	}
}

int main()
{
	int n, m, s;
	cin >> n;
	cin >> m;

	vector<int>* v = new vector<int>[n + 1];
	bool* visited = new bool[n + 1];

	for (int i = 0; i < n + 1; i++)
	{
		visited[i] = false;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(v[i].begin(), v[i].end());
	}

	cin >> s;

	BFS(s, v, visited);
	cout << endl;

	return 0;
}