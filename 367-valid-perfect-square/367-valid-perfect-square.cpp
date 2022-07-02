class Solution {
public:
    bool isPerfectSquare(int num) {
        long long  i=2 ;
        while(num>=i*i){
            if(i*i == num)
                return 1;
            i++;
        }
        if(num == 1) return 1;
        return 0;
    }
};