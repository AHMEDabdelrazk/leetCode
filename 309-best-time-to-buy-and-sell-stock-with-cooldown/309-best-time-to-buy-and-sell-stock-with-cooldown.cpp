class Solution {
public:
    vector<vector<int>> dp;
    int util(vector<int>& prices, int i, bool buy)
    {
        if(i >= prices.size())
            return 0;
        if(dp[i][buy] != -1)
            return dp[i][buy];
        int cooling = util(prices,i+1,buy); //just skip the current iteration
        if(buy)
        {
            int buying = util(prices,i+1,false) - prices[i]; //buying at present iteration
            dp[i][buy] = max(buying,cooling);
        }
        else
        {
            //selling at present iteration (notice if you sell at i, you have to cooldown at i+1)
            int selling = util(prices,i+2,true) + prices[i]; 
            dp[i][buy] = max(selling,cooling);
        }
            return dp[i][buy];
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return util(prices,0,true);
    }
};