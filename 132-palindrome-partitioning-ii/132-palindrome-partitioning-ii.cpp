class Solution {
public:
    int dp[2000+7] ; 
    string s;
    int n ;
    /*    check if palindrome   */
    bool pal(int j,int i){
        while(i<=j)
        {
            if(s[i]!=s[j])return false;
            i++;j--;
        }
        return true;
    }
    /*    d_p function         */
    int dynamic( int I){
        if(I >= n)
            return 0;
        if(dp[I]!=-1)
            return dp[I];
        int ans = INT_MAX;
        for(int i=I;i<n;i++){
            if(pal(i,I))
                ans=min(ans,dynamic(i+1)+1);
        }
        return dp[I]=ans;
    }
    /*    mini cut fun         */
    int minCut(string s) {
        n = s.size() , this->s = s ;
        memset(dp,-1,sizeof(dp));
        return dynamic(0)-1;
    }
};