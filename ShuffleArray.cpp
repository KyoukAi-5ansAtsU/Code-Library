#include <bits/stdc++.h> 
using namespace std; 

void shuffleArrayRecursive(int left, int right, int arr[]) { 	
	if (right - left == 1) 
		return; 
	
	int middle = (left + right) / 2; 
  	
	int mmiddle = (left + middle) / 2; 
	
	int temp = middle + 1; 
	
	for (int i = mmiddle + 1; i <= middle; i++) 
		swap(arr[i], arr[temp++]); 
	  
	shuffleArrayRecursive(left, middle, arr); 
	shuffleArrayRecursive(middle + 1, right, arr); 
} 

void shuffler(int a[], int n){
	shuffleArrayRecursive(0, n-1, a);
}

int main() { 
	int a[] = { 1, 3, 5, 7, 2, 4, 6, 8 }; 
	int n = sizeof(a) / sizeof(a[0]); 
	shuffler(a, n); 
  
	for (int i = 0; i < n; i++) 
		cout << a[i] << " "; 
  
	return 0; 
} 