class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size());
        for(int i=0;i<nums.size();i++){
            for(int j=i+1 ; j<i+nums[i]+1 && j<nums.size() ; j++){
                if(dp[j]!=0) dp[j] = min(dp[j],dp[i]+1);
                else dp[j] = dp[i]+1;
            }
        } 
        int n = max<int>(0,nums.size()-1);
        return dp[n];
    }
};