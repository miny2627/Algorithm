#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void DFS(int s, vector<int>* v, bool* visited)
{
	visited[s] = true;
	cout << s << " ";

	for (int i = 0; i < v[s].size(); i++)
	{
		int tmp = v[s][i];

		if (visited[tmp] == false)
		{
			DFS(tmp, v, visited);
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

	DFS(s, v, visited);
	cout << endl;

	return 0;
}