class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
       int dp[n+1];
        if(n==0)
            return 1;
        dp[0]=1;
        dp[1]=10;
        for(int i=2;i<=n;i++)
        {
            int ans=9;
            int cnt=9;
            for(int j=1;j<i;j++)
            {
                ans=ans*cnt;
                 cnt--;
            }
            dp[i]=ans+dp[i-1];
        }
        return dp[n];
    }
};