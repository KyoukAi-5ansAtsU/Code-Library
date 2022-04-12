#include <bits/stdc++.h>
using namespace std;

int answerQuery(int a[], int n,
				int l, int r)
{	
	int count = 0;
	
	l = l - 1;
	
	for (int i = l; i < r; i++)
	{
		int element = a[i];
		int divisors = 0;
				
		for (int j = l; j < r; j++)
		{			
			if (a[j] % a[i] == 0)
				divisors++;
			else
				break;
		}
				
		if (divisors == (r - l))
			count++;
	}
	
	return count;
}

int main()
{
	int a[] = { 1, 2, 3, 5 };
	int n = sizeof(a) / sizeof(a[0]);

	int l = 1, r = 4;
	cout << answerQuery(a, n, l, r) << endl;

	l = 2, r = 4;
	cout << answerQuery(a, n, l, r) << endl;
	return 0;
}
