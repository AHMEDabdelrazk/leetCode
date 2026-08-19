class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        int res = 0, j = 1, mx = 0;
        std::sort(rs.begin(), rs.end());
        for(int i=0;i<rs.size();i++){
            bool b1 = 0, b2 = 0, b3 = 0;
            if(rs[i][0] != j) {res+=2; j++; --i; continue;}
            while(i<rs.size()){
                if(std::clamp(rs[i][1], 2, 5) == rs[i][1]) b1 = 1;
                if(std::clamp(rs[i][1], 4, 7) == rs[i][1]) b2 = 1;
                if(std::clamp(rs[i][1], 6, 9) == rs[i][1]) b3 = 1;
                ++i;
                if(i<rs.size()&&rs[i][0] != j){--i;break;} 
            }
            int res1 = 0, res2 = 0;
            if(!b1) res1++;
            if(!b2) res2++;
            if(!b3) res1++;
            res+=max(res1,res2);
            cout<<res;
            j++;
        }
        for(int i=j;i<=n;i++) res+=2;
        return res;
    }
};