public class Solution {
    public long[] ResultArray(int[] nums, int k) {
        long[] ans = new long[k];
        long[] dp = new long[k];

        foreach (int num in nums) {
            long[] newDp = new long[k];
            int numMod = num % k;
            
            newDp[numMod] += 1;

            for (int i = 0; i < k; i++) {
                int newMod = (int)((long)i * numMod % k);
                newDp[newMod] += dp[i];
            }

            for (int i = 0; i < k; i++) {
                ans[i] += newDp[i];
            }

            dp = newDp;
        }

        return ans;
    }
}