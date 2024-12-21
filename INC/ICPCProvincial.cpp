#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
    long long int size;
   	scanf ("%lld", &size);
    
    vector<int> team(3 * size);

    for (int i = 0; i < 3 * size; i++) {
        cin >> team[i];
    }
    
    sort(team.begin(), team.end());

    printf ("%lld\n", team[size]);
    
    return 0;
    
}

