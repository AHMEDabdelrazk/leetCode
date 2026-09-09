class Solution {
public:
    long long countCommas(long long n) {
        return max(1LL * 0, 1LL * (min(1LL*999999,n) - 999) ) +
               max(1LL * 0, 1LL * (min(1LL*999999999,n) - 999999) * 2) +
               max(1LL * 0, 1LL * (min(1LL*999999999999,n) - 999999999) * 3 ) + 
               max(1LL * 0, 1LL * (min(1LL*999999999999999,n) - 999999999999) * 4 ) +
               max(1LL * 0, 1LL * (1 + n - 1000000000000000) * 5 );
    }
};