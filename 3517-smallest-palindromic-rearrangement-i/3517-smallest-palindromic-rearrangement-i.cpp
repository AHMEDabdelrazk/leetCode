class Solution {
public:
    string smallestPalindrome(string s) {
        // common
        map<char, int> frq;
        char odd_chr = 0;
        int n = s.size();
        string result = "", rev = "";
        for(int i=0;i<n;i++) frq[s[i]]++;
        for(auto &e: frq) if(e.second%2!=0) (odd_chr = e.first);
        for(auto &e: frq)
        for(int i=0;i<e.second/2;i++) result+=e.first; 
        rev=result; if(odd_chr)result+=odd_chr; reverse(rev.begin(), rev.end());
        return (result + rev);


        // case 1 (input == output)
        // case 2 (sort input with odd middle)
        // case 3 (sort input all even)
    }
};