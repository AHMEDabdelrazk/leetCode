class Solution {
public:
    int solve(string &s,string &p,unordered_set<int> &st)
    {
        int i = 0, j = 0;
        while(i<s.size() and j<p.size())
        {
            if(st.find(i)!=st.end() or s[i]!=p[j])
            {
                i++;
                continue;
            }
            i++;
            j++;
        }
        return j==p.size();
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n = removable.size();
        int l = 0, h = n - 1;
        int ans = 0;
        while(l<=h)
        {
            int mid = (l + h)/2;
            unordered_set<int> st(removable.begin(),removable.begin() + mid + 1);
            if(solve(s,p,st))
            {
                ans = max(ans,mid + 1);
                l = mid + 1;
            }
            else
                h = mid - 1;
        }
        return ans;
    }
};