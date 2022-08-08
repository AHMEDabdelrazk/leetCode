class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        if(nums.size() == 1)return nums[0]>0;
        int l=0;
        int ans=0;
        int n=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] <0)n++;
            if(nums[i]==0){
                l=i+1;
                n=0;
            }
           
           if(nums[i]!=0 && n%2 ==0)ans = max(ans,i+1-l);
        }
        n=0,l=nums.size();
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i] <0)n++;
            if(nums[i]==0){
                l=i;
                n=0;
            }
            
            if(n%2 ==0)ans = max(ans,l-i);
            
        }
        return ans;
    }
};