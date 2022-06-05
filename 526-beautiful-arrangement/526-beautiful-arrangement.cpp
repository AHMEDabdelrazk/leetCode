class Solution {
public:
    void solve(int index, int n, int &count, unordered_map<int,int> &vis)
    {
        if(index>n)
        {
            count++;
            return;
        }
        // now calling a for loop to place digits
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0 && (index%i==0 || i%index==0))
            {
                vis[i]=1;
                solve(index+1,n,count,vis);
                vis[i]=0;
            }
        }
    }
    
    int countArrangement(int n) {
        int count=0;
        unordered_map<int,int> vis;
        solve(1,n,count,vis);
        return count;
    }
};