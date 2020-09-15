#include <iostream>
using namespace std;

typedef struct tree {
	int key;
	tree* left;
	tree* right;
}node;

typedef node* Nptr;

Nptr Insert(Nptr t, int x)
{
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

void Delete(Nptr &t, int x)
{
	if (t == NULL) return;
	
	else if (t->key < x)
		Delete(t->right, x);

	else if (t->key > x)
		Delete(t->left, x);

	else
	{
		if ((t->left == NULL) && (t->right == NULL))
		{
			Nptr tmp = t;
			t = NULL;
			delete tmp;
		}
		else if (t->left == NULL)
		{
			Nptr tmp = t;
			t = t->right;
			delete tmp;
		}
		else if (t->right == NULL)
		{
			Nptr tmp = t;
			t = t->left;
			delete tmp;
		}
		else
		{
			Nptr tmp = t->right;
			Nptr p = new node;
			while (tmp->left != NULL)
			{
				p = tmp;
				tmp = tmp->left;
			}
			t->key = tmp->key;

			if (tmp == t->right) t->right = tmp->right;
			else p->left = tmp->right;
		}
	}
}

void inorder(Nptr t)
{
	if (t == NULL) return;
	inorder(t->left);
	cout << t->key << " ";
	inorder(t->right);
}

void preorder(Nptr t)
{
	if (t == NULL) return;
	cout << t->key << " ";
	preorder(t->left);
	preorder(t->right);
}

void postorder(Nptr t)
{
	if (t == NULL) return;
	postorder(t->left);
	postorder(t->right);
	cout << t->key << " ";
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

	int k, p, x;
	cin >> k;
	
	for (int i = 0; i < k; i++)
	{
		cin >> p >> x;
		Delete(t, x);

		if (p == 0)
		{
			preorder(t);
			cout << endl;
		}
		else if (p == 1)
		{
			inorder(t);
			cout << endl;
		}
		else if (p == 2)
		{
			postorder(t);
			cout << endl;
		}
		else break;
	}
	

	return 0;
}