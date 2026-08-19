class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        int res = 0, j = 1, mx = 0;
        // sorting to walking from 1 to n and 
        std::sort(rs.begin(), rs.end());
        // loop only over the reservedSeats
        for(int i=0;i<rs.size();i++){
            bool b1 = 0, b2 = 0, b3 = 0;
            // the rows that is empty
            if(rs[i][0] != j) {res+=2; j++; --i; continue;}
            // rows with reserved seats
            while(i<rs.size()){
                if(std::clamp(rs[i][1], 2, 5) == rs[i][1]) b1 = 1;
                if(std::clamp(rs[i][1], 4, 7) == rs[i][1]) b2 = 1;
                if(std::clamp(rs[i][1], 6, 9) == rs[i][1]) b3 = 1;
                ++i;
                if(i<rs.size()&&rs[i][0] != j){--i;break;} 
            }
            // choose one of the two pattern results 
            int res1 = 0, res2 = 0;
            if(!b1) res1++;
            if(!b2) res2++;
            if(!b3) res1++;
            res+=max(res1,res2);
            // j is from 0 - n
            j++;
        }
        // the rows that is empty after
        for(int i=j;i<=n;i++) res+=2;
        return res;
    }
};