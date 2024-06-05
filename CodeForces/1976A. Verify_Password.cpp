// Link: https://codeforces.com/contest/1976/problem/A

#include <stdio.h>
#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int main(){
	
	int test;
	scanf ("%d", &test);
	
	for (int i = 0; i < test; i++){
		int length;
		scanf ("%d", &length);
		
		char pass[length];
		cin >> pass;
		
		int n = strlen (pass);
	    int lastDigit = -1;
	    int lastLetter = -1;
	    
	    bool validation = true;
	    
	    for (char ch : pass) {
	    	
	        if (isdigit(ch)) {
	            int digitValue = ch - '0';
	            if (lastLetter != -1) {
	                validation = false;
	                break;
	            }
	            if (digitValue < lastDigit) {
	                validation = false;
	                break;
	            }
	            lastDigit = digitValue;
	        } 
			
			else if (isalpha(ch)) {
				if (ch >= 'A' && ch <= 'Z'){
					validation = false;
	                break;
				}
	            if (ch < lastLetter) {
	                validation = false;
	                break;
	            }
	            lastLetter = ch;
	        }
	        
	        else {
	        	validation = false;
	        	break;
			}
	        
	    }
	    
	    if (validation) printf ("YES\n");
	    else printf ("NO\n");
		
	}
	
	return 0;
}
