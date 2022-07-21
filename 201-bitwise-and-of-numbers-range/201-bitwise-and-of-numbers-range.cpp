class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for (int k = 31; k >= 0; k--) {
            int l = (left >> k) & 1; //extract bit from MSB to LSB from left
            int r = (right >> k) & 1; //extract bit from MSB to LSB from right
            if (l == r) ans = ans | (l << k);
            else break;
        }
        
        return ans;
    }
};