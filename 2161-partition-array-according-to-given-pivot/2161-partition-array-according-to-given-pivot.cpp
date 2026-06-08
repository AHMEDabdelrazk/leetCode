class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>v1,v2,v3,res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>pivot)
                v1.push_back(nums[i]);
            else if(nums[i]<pivot)
                v2.push_back(nums[i]);
            else 
                v3.push_back(pivot);
        }
        for(auto s:v2) res.push_back(s);
        for(auto s:v3) res.push_back(s);
        for(auto s:v1) res.push_back(s);
        return res;
    }
};