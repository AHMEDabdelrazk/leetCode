class Solution {
public:
    int nearestExit(vector<vector<char>>& m, vector<int>& e) {
        queue<pair<int,int>> q;
        q.push({e[0],e[1]});
        int c=0,mm=INT_MAX;
        m[e[0]][e[1]]='+';
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
            int i=q.front().first,j=q.front().second;
            q.pop();
            //cout<<i<<j<<endl;    
            if((i*j==0 || i==m.size()-1 || j==m[0].size()-1) && c!=0)
            mm=min(mm,c);
                if(j<m[0].size()-1 && m[i][j+1]=='.')
                    {q.push({i,j+1});m[i][j+1]='+';}
                if(j>0 && m[i][j-1]=='.')
                    {q.push({i,j-1});m[i][j-1]='+';}
                if(i<m.size()-1 && m[i+1][j]=='.')
                   { q.push({i+1,j});m[i+1][j]='+';}
                if(i>0 && m[i-1][j]=='.')
                    {q.push({i-1,j});m[i-1][j]='+';}
            }
            c++;
            if(mm!=INT_MAX)
                return mm;
        }
        if(mm==INT_MAX)
            mm=-1;
        return mm;
    } 
};