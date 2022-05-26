class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int coun = n ;
        for(int i = 5 ; coun > 0 ; i *= 5){
            ans += n/i;
            coun = n/i;
        }
        return ans;
    }
};