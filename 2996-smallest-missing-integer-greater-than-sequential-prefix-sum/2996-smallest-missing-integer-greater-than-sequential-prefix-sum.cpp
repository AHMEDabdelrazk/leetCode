class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int x = nums[0];
        unordered_map<int,bool> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]] = true;
        }
        for(int i=1;i<n;i++){
            if(nums[i]!=(nums[i-1]+1)){
                break;
            }else{
                x+=nums[i];
            }
        }
        while(mp[x]) x++;
        return x;
    }
};