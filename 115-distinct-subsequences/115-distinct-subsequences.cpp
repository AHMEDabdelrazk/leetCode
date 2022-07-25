class Solution {
public:
    int numDistinct(string s, string t) {
        
        int tn = t.size(), sn = s.size();
        
        int cnt = 0;
        
        unsigned long long int dp[1+1][tn+1];
        
        for(int i = 0 ; i<=sn ; i++)
        {
            for(int j = 0; j <= tn ; j++)
            {
                if(j==0)
                    dp[i%2][j] = 1;
                else if(i==0)
                    dp[i%2][j] = 0;
                else
                {
                    dp[i%2][j] = dp[(i-1)%2][j-1] * (s[i-1]==t[j-1]) + dp[(i-1)%2][j];
       
                }
                
                
            }
        }
        
        return dp[sn%2][tn];
        
    }
};