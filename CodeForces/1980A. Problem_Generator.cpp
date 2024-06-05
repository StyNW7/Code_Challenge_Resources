// Link: https://codeforces.com/contest/1980/problem/A

#include <bits/stdc++.h>

int main(){
	
	int test;
	scanf ("%d", &test);
	
	for (int i = 0; i < test; i++){
		int size, count;
		scanf ("%d %d", &size, &count);
		
		char prob[size];
		scanf ("%s", prob);
		
		int ans = 0;
		
		int hash[7] = {0};
		
		for (int x = 0; x < size; x++){
			hash[prob[x]-'A']++;
		}
		
		for (int y = 0; y < 7; y++){
			if (hash[y] < count) ans += (count-hash[y]);
		}
		
//		printf ("%d\n", hash[0]);
		printf ("%d\n", ans);
		
	}
	
	return 0;
}
