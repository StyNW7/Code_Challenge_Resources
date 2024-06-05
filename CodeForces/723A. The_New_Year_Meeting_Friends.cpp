// Linkk: https://codeforces.com/contest/723/problem/A

#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
	
	int arr[3];
	for (int i = 0; i < 3; i++) cin >> arr[i];
	
	sort (arr, arr+3);
	
	printf ("%d\n", abs (arr[0] - arr[1]) + abs (arr[1] - arr[2]));
	
	return 0;
}
