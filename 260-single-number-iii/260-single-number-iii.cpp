class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int> res;
        for(auto a:mp)
            if(a.second<2)
                res.push_back(a.first);
        return res;
    }
};