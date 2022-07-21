class Solution {
public:
    int countPrimes(int n) {
        // seive of Erastosthnes
        vector<bool>isPrime(n,true);
        int count  = 0;
        for(int i = 2; i <= n /2;i++)
        {
//          mark false as non prime
            if(isPrime[i]) {
                for(int j = 2 * i;j < n;j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        for(int i = 2;i < n;i++) {
            if(isPrime[i])
                count++;
        }
        return count;
     }
};