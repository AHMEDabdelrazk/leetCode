class Solution {
public:

int n,m;

void gp(vector<vector<int>>& v,int i,int j,int c,int k)
{
    if(i<0 || i>=n || j<0 || j>=m)
    {
        return;
    }
    if(v[i][j]==c)
    {
        v[i][j]=k;
        gp(v,i+1,j,c,k);
        gp(v,i-1,j,c,k);
        gp(v,i,j+1,c,k);
        gp(v,i,j-1,c,k);
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& v, int i, int j, int k) {
    n=v.size(),m=v[0].size();
    int c=v[i][j];
    if(c==k)
    {
        return v;
    }
    gp(v,i,j,c,k);
    return v;
}
};