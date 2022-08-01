class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo (m,vector<int>(n));
       for(int i=0;i<m;i++)for(int j=0;j<n;j++)
            (!i||!j)?memo[i][j]=1:memo[i][j]=memo[i-1][j]+memo[i][j-1];
        return memo[m-1][n-1];
    }
};