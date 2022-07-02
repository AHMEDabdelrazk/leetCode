class Solution {
public:
    void solve( set<long long> &s, long long num){
        if(num >=INT_MAX) return;
        if( s.find(num)!=s.end()) return;
        s.insert(num);
        solve(s, num*2);
        solve(s, num*3);
        solve(s, num*5);
    }
    int nthUglyNumber(int n) {
        set<long long> s;
        solve( s, 1);
        int ans =n;
        for( auto i: s){
            n--;
            if( n==0) ans = i;
        }
        return ans;
    }
};
