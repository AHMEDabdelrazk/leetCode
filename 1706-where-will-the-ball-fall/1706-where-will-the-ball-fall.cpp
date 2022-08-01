class Solution {
public:
    int dfs(vector<vector<int>>&grid,int r,int c)
    {
        if(r<0 || c<0 || c>=grid[0].size())
            return -1;
        if(r==grid.size())  // reached at last row, so column no. will be our answer
            return c;
        if(grid[r][c]==1 && c<grid[0].size()-1 && grid[r][c+1]==1)  // can I go right side ?
            return dfs(grid,r+1,c+1);
        if(grid[r][c]==-1 && c>0 && grid[r][c-1]==-1)  // can I go left side ?
            return dfs(grid,r+1,c-1);
        return -1;   //otherwise i can't go anywhere
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>ans;
        for(int i=0;i<grid[0].size();i++)
            ans.push_back(dfs(grid,0,i));
        return ans;
    }
};