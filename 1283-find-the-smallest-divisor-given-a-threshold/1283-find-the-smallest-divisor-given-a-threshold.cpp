class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int m = l+(r-l)/2;
            if (doit(nums, m) <= threshold) {
                r = m;
            } else {
                l = m+1; 
            }
        }
        return l;
    }
    
    int doit(vector<int>&nums, int k) {
        return accumulate(nums.begin(), nums.end(), 0, [k](int a, int b) {
            return a + b/k + (b%k != 0);
        });
    }
};