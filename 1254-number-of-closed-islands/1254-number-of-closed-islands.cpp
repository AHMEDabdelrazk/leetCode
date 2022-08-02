class Solution {
public:
    vector<int> row={0,0,-1,1};
    vector<int> col={-1,1,0,0};
    int DFS(vector<vector<int>>& grid,int r,int c,int n,int m,vector<vector<int>>& vis){
        if(r*c==0 || r==n-1|| c==m-1)
            return 0;
        vis[r][c]=1;
        int ans=1;
        for(int i=0;i<4;i++)
        {
            int r_new=r-row[i];
            int c_new=c-col[i];
            if(r_new>=0 && r_new<n && c_new>=0 && c_new<m && !vis[r_new][c_new] && grid[r_new][c_new]==0)
            {
                int x=DFS(grid,r_new,c_new,n,m,vis);
                ans=ans&x;
            }
        }
        return (ans==1)?1:0;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        if(r<=2 || c<=2)
            return 0;
        int ans=0;
        vector<vector<int>> vis(r,vector<int>(c, 0));
        for(int i=1;i<r-1;i++)
        {
            for(int j=1;j<c-1;j++)
            {
                if(!vis[i][j] && grid[i][j]==0){
                    ans+=DFS(grid,i,j,r,c,vis);
                }
            }
        }
        return ans;
    }
};