class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        bool arr[101]={0};
        int n = nums.size(), K=k;
        for(int i=0;i<n;i++) arr[nums[i]] = 1;
        while(K<101){
            if(!arr[K]) return K;
            K+=k;
        }
        return K;
    }
};