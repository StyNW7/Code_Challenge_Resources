// Link: https://codeforces.com/contest/1976/problem/B

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<long long int> b(n + 1);
        for (int i = 0; i < n + 1; ++i) {
            cin >> b[i];
        }

        long long int operation = 0;
        long long distance = 9999999999;
        bool copy = false;
        
        for (int i = 0; i < n; i++){
        	
        	distance = min(distance, abs(a[i] - b[n]));
        	
        	if (!copy && ((b[n] <= a[i] && b[n] >= b[i]) || (b[n] >= a[i] && b[n] <= b[i]))){
        		copy = true;
        		operation++;
			}
			
			distance = min(distance, abs(b[i] - b[n]));
			
			operation += abs(a[i] - b[i]);
        	
		}
		
		if (copy) printf ("%lld\n", operation);
		else {
			operation++;
			operation += distance;
			printf ("%lld\n", operation);
		}
        
    }

    return 0;
}
 
