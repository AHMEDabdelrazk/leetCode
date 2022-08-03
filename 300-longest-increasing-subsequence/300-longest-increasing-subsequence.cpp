class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int arr[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=1;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j]&&arr[i]<arr[j]+1)
                {
                    arr[i]=arr[j]+1;
                }
            }
        }
        sort(arr,arr+n);
        return arr[n-1];
    }
};