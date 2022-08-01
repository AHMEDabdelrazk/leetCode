class Solution {
public:
    int Occurence(vector<int> &arr, int target, int toggle)
    {
        int mid = 0, l = 0, h = arr.size()-1;
        int temp = -1;    
        while(l<=h)
        {
            mid = l+(h-l)/2;
           if(target == arr[mid])
            {
                temp = mid;
                if(toggle == -1) {
                    l = mid+1;
                }
                else {
                    h = mid-1;    
                }
            }
            else if(target > arr[mid])
                l = mid+1;
            else if(target < arr[mid])
                h = mid-1;
        }
        return temp;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = Occurence(nums,target,1);
        int b = Occurence(nums,target,-1);
        
        vector<int> r;
        
        r.push_back(a);
        r.push_back(b);
        
        return r;
    }
};