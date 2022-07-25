class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int l =0;
        int h=nums.size()-1;
        int mini= INT_MAX;
        if(nums.size()==1){return nums[0];}
        while(l<=h)
        {
            int mid =(l+h)/2;
            if(nums[mid]>nums[l])//if L array is sorted
            {   
                mini= min(mini,nums[l]);
                l=mid+1;
            }
            else if(nums[mid]<nums[l])
            {
                mini= min(mini,nums[mid]);
                h=mid-1;
            }
            else{
                mini=min(mini,nums[l]);
              l++;
                
            }
        }
        return mini;
    }
};