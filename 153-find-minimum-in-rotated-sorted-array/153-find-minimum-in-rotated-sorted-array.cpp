class Solution {
public:
  int findMin(vector<int>& nums) {

    if(nums.size()==1){
      return nums[0];
    }
    
    int l=0;
    int r=nums.size()-1;
    int pivot=nums[0];
    
    while(l<r){
      int mid=l+(r-l)/2;
      if(pivot<=nums[mid])
        l=mid+1;
      else
        r=mid;
      if(l==r && pivot>nums[l])
        pivot=nums[l];
    }
    
    return pivot;
  }
};