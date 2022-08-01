class Solution {
public:
    int n , m , r=0 , I , J  ;
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int,int>>Q;
        n = grid[0].size();
        m = grid.size();
        vector<vector<int>>vis(m,vector<int>(n));
        vector<vector<char>>g=grid;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]=='1'&&!vis[i][j]){
                  //  cout<<i<<" "<<j<<" - ";
                    r++;
                    vis[i][j]=1;
                    if(j+1<n&&g[i][j+1]=='1')Q.push(make_pair(i,j+1)),vis[i][j+1]=1;
                    if(i+1<m&&g[i+1][j]=='1')Q.push(make_pair(i+1,j)),vis[i+1][j]=1;
                    while(!Q.empty()){
                        pair<int,int>p=Q.front(); Q.pop(); 
                        I = p.first, J = p.second;
                        if(J<n-1&&g[I][J+1]=='1'&&!vis[I][J+1])
                            Q.push(make_pair(I,J+1)),vis[I][J+1]=1;
                        if(I<m-1&&g[I+1][J]=='1'&&!vis[I+1][J])
                            Q.push(make_pair(I+1,J)),vis[I+1][J]=1;
                        if(I>0&&g[I-1][J]=='1'&&!vis[I-1][J])
                            Q.push(make_pair(I-1,J)),vis[I-1][J]=1;
                        if(J>0&&g[I][J-1]=='1'&&!vis[I][J-1])
                            Q.push(make_pair(I,J-1)),vis[I][J-1]=1;
                    }
                }
            }
        } 
        return r;
    }
};