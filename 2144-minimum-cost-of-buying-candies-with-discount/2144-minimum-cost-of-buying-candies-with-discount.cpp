class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int res=0;
        for(int i=0;i<cost.size();i++){
            res+=cost[i];
        }
        sort(cost.begin(),cost.end());
        for(int i=cost.size()-3;i>=0;i-=3){
            res-=cost[i];
        }
        return res;
    }
};