class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum = 0, prd = 1, N = n;
        while(N){
            int dig = N%10;
            sum+=dig;
            prd*=dig;
            N/=10;
        }
        return (n%(sum+prd)==0);
    }
};