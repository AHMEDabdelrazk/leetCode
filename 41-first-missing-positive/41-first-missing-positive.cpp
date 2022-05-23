class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int mn = 1, mx = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mx = max(mx,nums[i]);
            mp[nums[i]]=1;
        }
        for(int i=1;i<=nums.size()+1;i++)
            if(!mp[i])
                return i;
        return 1;
    }
};