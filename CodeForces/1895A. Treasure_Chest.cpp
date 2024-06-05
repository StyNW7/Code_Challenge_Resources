// Link: https://codeforces.com/contest/1895/problem/A

#include <stdio.h>
#include <numeric>
#include <algorithm>

using namespace std;

int main(){
	
	int test;
	scanf("%d", &test);
	
	for (int i = 1; i <= test; i++){
		int treasure, key, stamina;
		scanf("%d %d %d", &treasure, &key, &stamina);
		int time = 0;
		if (key < treasure){
			time = treasure;
		}
		else {
			if (key + stamina == treasure){
				time = treasure;
			}
			else {
				time = key + std::max (0, key - treasure - stamina);
			}
		}
		printf("%d\n", time);
	}
	
	return 0;
}
