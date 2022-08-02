class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        int n=a.size()-1;
        int l=0,r=a.size()-k,mid;
        
        while(l<r){
            mid = l + (r-l)/2;
            if(x-a[mid] > a[mid +k] -x)l=mid+1;
            else r= mid;
        }
        vector<int> ans;
        for(int i=l;i<l+k;i++){
             ans.push_back(a[i]);
         }
        return ans;
    }
}; 