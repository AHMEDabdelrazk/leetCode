class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int R=-1000000,res=0,r = 0;
        for(int i=0;i<nums.size();i++){
            res += nums[i];
            if(res<0)
                res = 0;
            r = max(r,res);
            R = max(R,nums[i]);
        }
        if(r==0)
            r=R;
        return r;
    }
};