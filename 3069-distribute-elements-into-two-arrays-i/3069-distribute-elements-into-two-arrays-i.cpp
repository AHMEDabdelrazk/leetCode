class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size(), c1 = 0, c2 = 0;
        vector<int> v1 = {nums[0]}; 
        vector<int> v2 = {nums[1]};
        for(int i=2;i<n;i++){
            if(v1[c1]>v2[c2]) v1.push_back(nums[i]),++c1;
            else v2.push_back(nums[i]), ++c2;
        }
        v1.insert(v1.end(), v2.begin(), v2.end());
        return v1;
    }
};