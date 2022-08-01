class Solution {
public:
     int triangleNumber(vector<int>& nums)
{
    int n=nums.size();;
    
    int res=0;
    
    sort(nums.begin(),nums.end());
    
    for(int i=0;i<n-2;i++)
        for(int j=i+1;j<n-1;j++)
        {
            int l=j+1;
            int r=n-1;
            
            int target=nums[i]+nums[j];
            
            int k=-1;
            
            while(l<=r)
            {
                int m=(l+r)/2;
                    
                if(nums[m]<target)
                    l=m+1,k=m;
                else r=m-1;
            }
            
          
            if(k!=-1)
                res+=k-j;

        }
    
    
    return res;
}
};