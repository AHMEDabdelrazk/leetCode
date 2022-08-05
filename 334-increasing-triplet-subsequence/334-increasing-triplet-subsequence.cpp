class Solution {
public:
bool increasingTriplet(vector<int>& nums) {

    int f1=INT_MAX;
    int f2=INT_MAX;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]<=f1)
        {
            f1=nums[i];
            
        }
        else if(nums[i]<=f2)
        {
            f2=nums[i];
        }
        else
            return true;
    }
    
    
    return false;
}
};

