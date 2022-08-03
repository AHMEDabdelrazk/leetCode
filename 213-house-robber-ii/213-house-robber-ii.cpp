class Solution {
public:
    int robber_maxi(vector<int>& tmp)
    {
        int n=tmp.size();
        int prev=tmp[0];
        int prev2=0;
        for(int i=1;i<n;i++)
        {
            int pick=tmp[i];
            if(i>1)
                pick += prev2;
            int notPick=0 + prev;
            int curr=max(pick,notPick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) 
    {
    vector<int> temp1,temp2;
        int n=nums.size();
        if(n==1)
            return nums[0];
    for(int i=0;i<n;i++)
    {
        if(i!=0)
            temp1.push_back(nums[i]);
        if(i!=n-1)
            temp2.push_back(nums[i]);
    }
        return max(robber_maxi(temp1),robber_maxi(temp2));
    }
};