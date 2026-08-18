class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(k >= nums.size()){
            return  *std::max_element(nums.begin(), nums.end());
        } else if( k != 1) {
            int mx =  max(nums[nums.size()-1], nums[0]);
            int frt = std::count(nums.begin(), nums.end(), nums[0]);
            int lst = std::count(nums.begin(), nums.end(), nums[nums.size()-1]);
            return frt > 1 ? (lst > 1 ? -1 : nums[nums.size()-1]) 
               : (lst > 1 ? nums[0] : mx);
        } else if(k == 1 ){
            sort(nums.begin(),nums.end());
            vector<bool> vst(nums.size(),false);
           for(int i=nums.size()-1;i>0;i--){
            if(!vst[nums[i]] && nums[i] != nums[i-1]) 
                return nums[i];
            vst[nums[i]] = true;
           }
           if(!vst[nums[0]]) return nums[0];
        } 
        return -1;
    }
};