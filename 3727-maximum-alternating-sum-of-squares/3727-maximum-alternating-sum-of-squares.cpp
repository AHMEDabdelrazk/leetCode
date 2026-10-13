class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(auto &e:nums) e = abs(e);
        sort(nums.begin(),nums.end());
        long long rs =0 ;
        int l=nums.size(),r=0,m=1;
        for(int i=0;l!=r && i<nums.size();i++){
            if(m) rs+=(nums[--l]*nums[l]),m=0;
            else rs-=(nums[r]*nums[r++]),m=1;
        }
        return rs;
    }
};