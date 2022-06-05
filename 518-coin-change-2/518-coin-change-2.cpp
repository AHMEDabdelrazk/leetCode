class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[300*2][5000*2]={};
        for(int i=0;i<coins.size();i++){
            dp[i][amount] = 1;
        }
        int anser;
        for(int i = coins.size()-1;i>=0;i--){
            for(int j=amount-1;j>=0;j--){
                dp[i][j]=dp[i+1][j]+dp[i][j+coins[i]];
                anser = dp[i][j];
            }
        }if(amount==0)anser=1;
        return anser;
    }
};