class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto s:nums)
            mp[s]++;
        for(auto s:nums)
            if(mp[s]>(nums.size()/2))
                return s;
        return 0;
    }
};