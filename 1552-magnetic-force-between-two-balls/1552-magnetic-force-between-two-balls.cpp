class Solution {
public:
    bool isValid(vector<int>& arr,int m,int distance){
        int balls = 1,prev = arr[0];
        for(int i = 1; i < arr.size(); i++){
            if(arr[i]-prev >= distance){
                prev = arr[i];
                balls++;
                if(balls == m)return true;
            }
        }
        if(balls < m)return false;
        return true;
    }
    int maxDistance(vector<int>& p, int m) {
        sort(p.begin(),p.end());
        int low = 0,high = p[p.size()-1],ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(isValid(p,m,mid)){
                ans = mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return ans;
    }
};