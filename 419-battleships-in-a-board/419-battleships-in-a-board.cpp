class Solution {
public:
    int vis[205][205];
    
    void dfs(int i,int j,int n,int m,vector<vector<char>> &v){
        if (i<0 || j<0 || i>=n || j>=m || v[i][j]=='.' || vis[i][j]){
            return;
        }
        
        vis[i][j]=1;
        v[i][j]='.';
        
        dfs(i+1,j,n,m,v);
        dfs(i-1,j,n,m,v);
        dfs(i,j+1,n,m,v);
        dfs(i,j-1,n,m,v);
        
        v[i][j]='X';
    }
    
    int countBattleships(vector<vector<char>>& v) {
       int i,j;
       int ct=0;
        
       for (i=0; i<v.size(); i++){
           for (j=0; j<v[0].size(); j++){
               if (v[i][j]=='X' && !vis[i][j]){
                   dfs(i,j,v.size(),v[0].size(),v);
                   ct++;
               }
           }
       } for (i=0; i<v.size(); i++){
           for (j=0; j<v[0].size(); j++){
               cout<<v[i][j]<<" ";
           }
           cout<<" | ";
       }
        
     return ct;
    }
};