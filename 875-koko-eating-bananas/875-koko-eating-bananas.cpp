class Solution {
private:
    bool check(int mid, int bound, vector<int> &piles){
        long long ct = 0;
        for(auto &e : piles){
            ct += (e % mid? 1 : 0) + e/mid;
        }
        return ct <= bound;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo =1, hi = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while(lo <= hi){
            int mid = (lo + hi)>>1;
            if(check(mid, h, piles)){
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};