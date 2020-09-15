#include <iostream>
using namespace std;

int count1 = 0;
int count2 = 0;

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int insertionsort(int *A, int n)
{
	int index;
	for (int i = 1; i < n; i++)
	{
		index = i;
		while (index > 0 && A[index] < A[index - 1])
		{
			swap(A[index], A[index - 1]);
			index--;
			count2++;
		}
		count1++;
	}
	return count1 + count2;
}

int main()
{
	int *A, n;
	cin >> n;
	A = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	cout << insertionsort(A, n) << endl;

	return 0;
}
