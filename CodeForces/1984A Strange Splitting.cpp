#include <bits/stdc++.h>
#include <string>

using namespace std;

int main(){
	
	int test;
	scanf ("%d", &test);
	
	for (int i = 0; i < test; i++){
		int size;
		scanf ("%d", &size);
		int arr[size];
		for (int j = 0; j < size; j++) scanf ("%d", &arr[j]);
		
		string word;
		bool result = false;
		int max = arr[size-1];
		int min = arr[0];
		int diff = max - min;
		word += 'R';
		word += 'B';
		if (diff == 0) {
			cout << "NO" << endl;
			continue;
		}
		else {
			for (int x = 2; x < size; x++) word+='R';
		}
		cout << "YES" << endl;
		cout << word <<endl;
	}
	
	return 0;
}
