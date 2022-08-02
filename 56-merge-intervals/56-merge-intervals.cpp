class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> I; I.push_back(intervals[0]);
        int lst = intervals[0][1] , l = 0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=lst &&  I[l][1]<intervals[i][1])
                I[l][1]=intervals[i][1] , lst = I[l][1];
            else if( I[l][1]<intervals[i][1])
                I.push_back(intervals[i]) , l++ , lst = I[l][1];
        }
        return I;
    }
};