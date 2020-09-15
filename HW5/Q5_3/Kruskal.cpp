#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Graph
{
	int v;
	int e;
	int w;
};

vector<Graph> edge;
int parent[10000];
bool check;

void make_set(int v)
{
	parent[v] = v;
}

int find_set(int u)
{
	if (u == parent[u])
		return parent[u];
	else
	{
		int tmp = find_set(parent[u]);
		return tmp;
	}
}

void union_set(int u, int v)
{
	check = false;
	u = find_set(u);
	v = find_set(v);

	if (u != v)
	{
		check = true;
		parent[v] = u;
	}
}

bool comp(Graph a, Graph b)
{
	return a.w < b.w;
}

int main()
{
	int n, m;
	Graph g;
	vector<int> a;
	int total = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		make_set(i);
	}

	for (int i = 0; i < m; i++)
	{
	
		cin >> g.v >> g.e >> g.w;
		edge.push_back(g);
	}

	sort(edge.begin(), edge.end(), comp);

	for (int i = 0; i < m; i++)
	{
		union_set(edge[i].v, edge[i].e);
		if (check == true)
		{
			total += edge[i].w;
			cout << edge[i].w << " ";
		}
	}

	cout << total << endl;

	return 0;
}