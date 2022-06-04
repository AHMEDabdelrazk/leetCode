class Solution {
public:
    vector<int> v;
    int mem[1000+7];
    int dynamic(int t){
        if(t == 0)
            return 1 ;
        if(mem[t] != -1)
            return mem[t];
        int ans =  0;
        for(int i=0;i<v.size();i++){
            if(t-v[i]>=0)
                ans += dynamic(t-v[i]);
        }
        return mem[t] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(mem,-1,sizeof(mem));
        v = nums ;
        int res = dynamic(target);
        return res;
    }
};