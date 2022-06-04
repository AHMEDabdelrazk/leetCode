class Solution {
public:
    int getSum(int a, unsigned int b) {
        int re;
        while(b){
            re = a ^ b;
        b = (a & b) << 1;
        a = re ;}
        return a;
    }
};