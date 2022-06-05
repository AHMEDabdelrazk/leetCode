class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
        vector<int> ans;
        int m = mat.size(), n = mat[0].size();
        
        for(int i=0; i<m+n-1; i++)
        {
            int y = i<n ? i:n-1, x = i<n ? 0:i-n+1;
            vector<int> temp;
            
            if(i%2 == 0)
            { 
                while(y >= 0 and y < n and x < m and x >= 0) temp.push_back(mat[x++][y--]);
                reverse(temp.begin(), temp.end());
                for(int num: temp) ans.push_back(num);
            }
            else 
                while(y >= 0 and y < n and x < m and x >= 0) ans.push_back(mat[x++][y--]);
        }
        return ans;
    }
};