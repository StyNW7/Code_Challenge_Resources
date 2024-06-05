#include  <bits/stdc++.h>

using namespace std;

int main(){
	
	int length;
	cin >> length;
	
	string str;
	cin >> str;
	
	int longest = 0, words = 0;
	int temp = 0;
	
	for (int i = 0; i < length; i++){
		
		if (str[i] == '_'){
			temp = 0;
		}
		
		else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
			temp++;
			if (longest < temp) longest = temp;
		}
		
		if (str[i] == '('){
			temp = 0;
			int index = i+1;
			int word = 0;
			int count = 0;
			while (str[index] != ')'){
				if (str[index] != '_'){
					word++;
				}
				else {
					if (word > 0) {
						count++;
						word = 0;
					}
				}
				index++;
			}
			words += count;
			if (str[index-1] != '_' && str[index-1] != ')' && str[index-1] != '(') words += 1;
			i = index;
		}
		
	}
	
	printf ("%d %d\n", longest, words);
	
	return 0;
}
