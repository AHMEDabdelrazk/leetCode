class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> V=triangle; 
        for(int i=1;i<V.size();i++){
            for(int j=0;j<V[i].size();j++){
                if(j==0) V[i][j]+=V[i-1][j];
                else if(j==V[i].size()-1) V[i][j]+=V[i-1][V[i-1].size()-1];
                else V[i][j] += min( V[i-1][j] , V[i-1][j-1] );
            }
        }
       /* for(int i=0;i<V.size();i++){
            for(int j=0;j<V[i].size();j++)
                cout<<V[i][j]<<" ";
            cout<<" | ";}*/
        int n = V.size()-1;
        sort(V[n].begin(),V[n].end());
        return V[n][0];
    }
};