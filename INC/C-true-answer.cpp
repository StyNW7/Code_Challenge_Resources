#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){
	
    long long N;
    cin >> N;
    vector<long long> A(N+1);

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    unordered_map<long long, long long> list;
    long long sum = 0, freq = 0, last = -1;

    for(int i = 0; i < N - 1; i++){
    	
        sum = A[i] + A[i+1];
        
        if(sum == last){
            last = -1; 
            continue; 
        }

        last = sum;
        list[sum]++;
        
    }

    for(auto& pair: list){
    	
        if(pair.second > freq){
            freq = pair.second;
        }
        
    }

    cout << freq << endl;
    
    return 0;

}
