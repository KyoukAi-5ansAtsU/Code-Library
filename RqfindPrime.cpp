#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

void sieveOfEratosthenes(bool isPrime[])
{
	isPrime[1] = false;

	for (int p = 2; p * p <= MAX; p++) {
				
		if (isPrime[p] == true) {
			
			for (int i = p * 2; i <= MAX; i += p)
				isPrime[i] = false;
		}
	}
}

int getMid(int s, int e) { return s + (e - s) / 2; }

int queryPrimesUtil(int* st, int ss, int se, int qs, int qe, int index)
{		
	if (qs <= ss && qe >= se)
		return st[index];
	
	if (se < qs || ss > qe)
		return 0;
	
	int mid = getMid(ss, se);
	return queryPrimesUtil(st, ss, mid, qs, qe, 2 * index + 1) +
		queryPrimesUtil(st, mid + 1, se, qs, qe, 2 * index + 2);
}

void updateValueUtil(int* st, int ss, int se, int i, int diff, int si)
{		
	if (i < ss || i > se)
		return;
		
	st[si] = st[si] + diff;
	if (se != ss) {
		int mid = getMid(ss, se);
		updateValueUtil(st, ss, mid, i, diff, 2 * si + 1);
		updateValueUtil(st, mid + 1, se, i, diff, 2 * si + 2);
	}
}

void updateValue(int arr[], int* st, int n, int i, int new_val,
											bool isPrime[])
{	
	if (i < 0 || i > n - 1) {
		printf("Invalid Input");
		return;
	}

	int diff, oldValue;

	oldValue = arr[i];
	
	arr[i] = new_val;
	
	if (isPrime[oldValue] && isPrime[new_val])
		return;
	
	if ((!isPrime[oldValue]) && (!isPrime[new_val]))
		return;
	
	if (isPrime[oldValue] && !isPrime[new_val]) {
		diff = -1;
	}
	
	if (!isPrime[oldValue] && isPrime[new_val]) {
		diff = 1;
	}
	
	updateValueUtil(st, 0, n - 1, i, diff, 0);
}

void queryPrimes(int* st, int n, int qs, int qe)
{
	int primesInRange = queryPrimesUtil(st, 0, n - 1, qs, qe, 0);

	cout << "Number of Primes in subarray from " << qs << " to "
		<< qe << " = " << primesInRange << "\n";
}

int constructSTUtil(int arr[], int ss, int se, int* st,
								int si, bool isPrime[])
{			
	if (ss == se) {
		
		if (isPrime[arr[ss]])
			st[si] = 1;	
		else
			st[si] = 0;
		
		return st[si];
	}
			
	int mid = getMid(ss, se);
	st[si] = constructSTUtil(arr, ss, mid, st,
							si * 2 + 1, isPrime) +
			constructSTUtil(arr, mid + 1, se, st,
							si * 2 + 2, isPrime);
	return st[si];
}

int* constructST(int arr[], int n, bool isPrime[])
{	
	
	int x = (int)(ceil(log2(n)));
	
	int max_size = 2 * (int)pow(2, x) - 1;

	int* st = new int[max_size];
	
	constructSTUtil(arr, 0, n - 1, st, 0, isPrime);
	
	return st;
}

int main()
{

	int arr[] = { 1, 2, 3, 5, 7, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);


	bool isPrime[MAX + 1];
	memset(isPrime, true, sizeof isPrime);
	sieveOfEratosthenes(isPrime);
	
	int* st = constructST(arr, n, isPrime);
	
	int start = 0;
	int end = 4;
	queryPrimes(st, n, start, end);
		
	int i = 3;
	int x = 6;
	updateValue(arr, st, n, i, x, isPrime);
		
	
	start = 0;
	end = 4;
	queryPrimes(st, n, start, end);

	return 0;
}
