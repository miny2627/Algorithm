#include <iostream>
using namespace std;

int result = 0;

typedef struct tree{
	int key;
	tree* left;
	tree* right;
}node;

typedef node* Nptr;

Nptr Insert(Nptr t, int x)
{
	result++;

	if (t == NULL)
	{
		Nptr temp = new node;
		temp->key = x;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	if (x < t->key)
	{
		t->left = Insert(t->left, x);
	}
	else
	{
		t->right = Insert(t->right, x);
	}
	return t;
}

int main()
{
	Nptr t = NULL;
	int n;
	cin >> n;
	int* a = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)
	{
		t = Insert(t, a[i]);
	}

	cout << result << endl;

	return 0;
}