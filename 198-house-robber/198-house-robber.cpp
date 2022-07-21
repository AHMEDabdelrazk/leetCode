class Solution {
public:
    int rob(vector<int>& nums) {
        return dp(nums.size() - 1, nums);
        
    }
    int dp(int n, vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]);
        if (!memo.count(n)) {
            memo[n] = max(dp(n - 2, nums) + nums[n], dp(n-1, nums));
        }
        return memo[n];
    }
private:
    unordered_map<int, int> memo;
};