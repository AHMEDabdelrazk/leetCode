class Solution {
public:
    bool canJump(vector<int>& nums) {
        int range=0;
        for(int i=0;i<nums.size();i++){
            if(i+1<=range || i==0)
                range = max(range , nums[i]+1+i);
        }
        return (range >= nums.size());
    }
};