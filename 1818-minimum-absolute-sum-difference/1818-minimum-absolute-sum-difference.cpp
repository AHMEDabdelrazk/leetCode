class Solution {
public:
    #define ll long long
    int mod = 1e9 + 7;
    ll max(ll a, ll b) {
        return a > b ? a : b;
    }
    int minAbsoluteSumDiff(vector<int>& a, vector<int>& b) {
        ll sum = 0; int n = a.size();
        vector<ll> aux;
        for(int i  = 0; i < n; i++) {
            sum+=abs(a[i] - b[i]); aux.push_back(a[i]);
        }
        
        sort(aux.begin(), aux.end());
        ll ans = sum;
        
        for(int i = 0; i < n; i++) {
            auto x = lower_bound(aux.begin(), aux.end(), b[i]);
            if(x != aux.end()) {
                ll temp = sum;
                temp-=abs(a[i] - b[i]);
                temp+=abs(*x - b[i]);
                ans = min(ans, temp);
            }
            
            auto y = upper_bound(aux.begin(), aux.end(), b[i]);
            if(y != aux.begin()) {
                y--;
                ll temp = sum;
                temp-=abs(a[i] - b[i]);
                temp+=abs(b[i] - *y);
                ans = min(ans, temp);
            }
        }
        
        return ans % mod;
    }
};