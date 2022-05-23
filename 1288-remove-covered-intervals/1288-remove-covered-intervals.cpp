class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int res = intervals.size();
        for(int i=0;i<intervals.size();i++)
            for(int j=0;j<intervals.size();j++)
if(i!=j&&intervals[i][0]!=-1&&intervals[i][0]>=intervals[j][0]&&intervals[i][1]<=intervals[j][1])                 {
                    res--;
                    //intervals[i][0]=-1;
                    break;
                }
        return res;
    }
};