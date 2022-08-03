class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        map<int,int> q;
        for(auto i:nums) q[i]++;
        vector<pair<int,int>> v;
        for(auto& p:q){
            v.push_back({p.first,p.second});
        }
        
        int a=0;
        int b=v[0].first*v[0].second;
        int c;
        for(auto i=1;i<v.size();i++){
            if(v[i].first-1==v[i-1].first){
                 c = max(a+v[i].first*v[i].second,b);
                 a=b;
                 b=c;
            }
            else{
                a=b;
                b=b+v[i].first*v[i].second;
            }
        }
        return b;
        
    }

};