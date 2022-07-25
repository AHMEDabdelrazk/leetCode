class Solution {
public:
    bool isMatch(string s, string p) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int slen = s.size(), plen = p.size(), i = 0, j = 0, match = -1, star = -1;
        while (i < slen) {
            if(j<plen && p[j]=='*') {
                match = i;
                star = j;
                j++;
            }
            else if(j<plen && p[j]=='?' || p[j]==s[i]) i++, j++;
            else if(star > -1) {
                i = match+1;
                j = star+1;
                match++;
            }
            else return false;
        }
        while (j<plen && p[j]=='*') j++;
        return (j==plen);
    }
};