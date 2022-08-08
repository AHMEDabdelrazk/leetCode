class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> ahead(2, 0), cur(2, 0);
        ahead[0] = ahead[1] = 0;
        for(int i = n - 1; i >=0; --i){
            for(int buy = 0; buy <=1; ++buy){
                int ct =0;
                if(buy){
                    ct += max(-prices[i] + ahead[0], 0 + ahead[1]);
                }
                else{
                    ct += max(prices[i] - fee + ahead[1], 0 + ahead[0]);
                }
                cur[buy] = ct;
            }
            ahead = cur;
        }
        return cur[1];
    }
};