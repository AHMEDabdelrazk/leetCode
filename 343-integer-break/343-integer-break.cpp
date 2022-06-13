class Solution {
public:
    int dp[5000];
    int f(int n)
    {
        if(dp[n]!=-1)
            return dp[n];
        else if(n<2)
            return 0;
        int ans=0;
        for(int k=1;k<n;k++)
        {
            int curr_max=max(n-k,f(n-k));
            ans=max(k*curr_max,ans);
        }
        return dp[n]=ans;
    }
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        return f(n);
    }
};