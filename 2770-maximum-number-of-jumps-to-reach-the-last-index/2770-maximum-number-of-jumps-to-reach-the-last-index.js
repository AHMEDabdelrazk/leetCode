/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var maximumJumps = function(nums, target) {
    const n = nums.length;
    const dp = Array(n).fill(-1);
    dp[0] = 0;
    for (let i = 1; i < n; i++) {
        for (let j = i - 1; j >= 0; j--) {
            if (-target <= nums[i] - nums[j] &&
                nums[i] - nums[j] <= target) {
                if (dp[j] > -1) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }
    }
    return dp[n - 1];
};