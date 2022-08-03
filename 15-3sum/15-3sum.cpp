class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        if(nums.size()==0 ||nums.size()==1 ||nums.size()==2){
            return {};
        }
        sort(nums.begin(),nums.end());
        
        if(nums[0]>0){
            return {};
        }
        for(int i=0;i<nums.size();i++){
            int low=i+1,j=nums.size()-1,sum=0;
            if(nums[i]>0){
                break;
            }
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }
            while(low<j){
                sum=nums[i]+nums[low]+nums[j];
                if(sum<0){
                    low++;
                }
                else if(sum>0){
                    j--;
                }
                else{
                    ans.push_back({nums[i],nums[low],nums[j]});
                    int last_low = nums[low] ; int last_high = nums[j];
                
                    
                    while (low < j && nums[low] == last_low)  low++;
                    while (low < j && nums[j] == last_high) j--;
                }
            }
        }
        return ans;
    }
};