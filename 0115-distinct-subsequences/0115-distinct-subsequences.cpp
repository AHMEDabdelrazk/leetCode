class Solution {
public:
    int numDistinct(string s, string t) {
        int sn = s.size();
        int tn = t.size();
        unsigned long long dp[sn + 1][tn + 1];

        // Base cases
        for (int i = 0; i <= sn; i++) {
            dp[i][0] = 1;
        }

        for (int j = 1; j <= tn; j++) {
            dp[0][j] = 0;
        }

        // Fill the DP table
        for (int i = 1; i <= sn; i++) {
            for (int j = 1; j <= tn; j++) {

                if (s[i - 1] == t[j - 1]) {
                    // Two choices:
                    // 1. Use s[i-1]
                    // 2. Skip s[i-1]
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else {
                    // Characters don't match.
                    // We must skip s[i-1].
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[sn][tn];
    }
};
