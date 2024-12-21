#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>


using namespace std;


int main(){
	
	
	int size;
	scanf ("%d", &size);
	getchar();
	
	
	char words[1001][1001];
	
	
	for (int i = 0; i < size; i++){
		scanf ("%s", words[i]);
		getchar();
	}
	
	
	for (int i = 0; i < size; i++){
		
		string word = words[i];
		string ans = "";
		
		int panjang = word.length();
		
		for (int i = 0; i < panjang; i++) {
    	
	        if (i < panjang - 1 && word[i] == 'c' && word[i + 1] == 'h') {
	        	
	            ans += 'c';
	            i++;
	            
	        }
	        
	        else if (word[i] == 'c') {
	        	
	            if (i == panjang - 1 || word[i + 1] == 'o' || word[i + 1] == 'u' || word[i + 1] == 'a' ||
	                (word[i + 1] != 'a' && word[i + 1] != 'u' && word[i + 1] != 'o' &&
	                 word[i + 1] != 'e' && word[i + 1] != 'y' && word[i + 1] != 'i')) {
	                 	
	                ans += 'k';
	                
	            } 
				
				else {
					
	                ans += 's';
	                
	            }
	            
	        }
	        
	        else {
	        	
	            ans += word[i];
	            
	        }
	        
	    }
	    
	    cout << ans << endl;
		
	}
	
	
	return 0;
	
}

