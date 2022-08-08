class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> p = prices;
        int I=0,J=1,R=0,f=0;
        for(int i=0;i<p.size()-1;i++){
            if(p[J-1]<=p[J])
                J++,f=1;
            else if(f){
                R+=p[J-1]-p[I];
                I=J,J++;
                f=0;
            }
            else
                I++,J++;
        }
        R+=p[J-1]-p[I];
        return R;
    }
};