class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int window_start = 0;
        int minLength = std::numeric_limits<int>::max();
        int sum = 0;
        
        for (int window_end = 0; window_end < nums.size(); ++window_end)
        {
            sum += nums[window_end];
            
            while (sum >= target)
            {
                minLength = min(minLength, window_end - window_start+1);
                sum -= nums[window_start];
                ++window_start;
            }
        }
        
        return minLength == std::numeric_limits<int>::max() ? 0: minLength;
        
    }
};