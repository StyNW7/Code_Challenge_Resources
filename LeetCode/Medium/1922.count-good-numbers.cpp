// Link: https://leetcode.com/problems/count-good-numbers/description/

class Solution {
public:

    const int MOD = 1e9 + 7;

    int countGoodNumbers(long long n) {
        
        long long evenPos = (n+1) / 2;
        long long oddPos = n / 2;

        long long evenVal = calculatePower(5, evenPos);
        long long oddVal = calculatePower(4, oddPos);

        return (evenVal * oddVal) % MOD;

    }

    // Util function

    long long calculatePower (long long base, long long power){

        long long result = 1;
        base %= MOD;

        while (power > 0){
            if (power % 2 == 1){
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            power /= 2;
        }

        return result;

    }

};
