class Solution {
public:
    const int MOD = 1e9 + 7;
    int distinctSubseqII(string s) {   
         vector<vector<int>> dp(s.length() + 1, vector<int>(26, 0));
        int n = s.size();
        for (int i = 1; i <= s.length(); i++) {
            dp[i] = dp[i - 1];
            int c = s[i - 1] - 'a';
            int total = 0;
            for (int j = 0; j < 26; j++) {
                total += dp[i - 1][j];
                total = total%MOD;
          }
            dp[i][c] = total%MOD + 1;
        }
        int answer = 0;
        for (int j = 0; j < 26; j++) {
            answer = (answer+dp[s.length()][j])%MOD;
        }
        return answer;
    }
};

/*
Processed	char	ending in a	ending in b	ending in c	Total
""      	—	    0	        0	        0	        0
"a"	        a	    1	        0	        0	        1
"ab"	    b	    1	        2	        0	        3
"abc"	    c	    1	        2	        4	        7

*/