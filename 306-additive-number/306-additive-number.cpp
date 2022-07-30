class Solution {
public:

string string_sum(string str1, string str2)
{
    if (str1.size() < str2.size())
        swap(str1, str2);

    int m = str1.size();
    int n = str2.size();
    string ans = "";

    // sum the str2 with str1
    int carry = 0;
    for (int i = 0; i < n; i++) {

        // Sum of current digits
        int ds = ((str1[m - 1 - i] - '0')
                  + (str2[n - 1 - i] - '0') + carry)
                 % 10;

        carry = ((str1[m - 1 - i] - '0')
                 + (str2[n - 1 - i] - '0') + carry)
                / 10;

        ans = char(ds + '0') + ans;
    }

    for (int i = n; i < m; i++) {
        int ds = (str1[m - 1 - i] - '0' + carry) % 10;
        carry = (str1[m - 1 - i] - '0' + carry) / 10;
        ans = char(ds + '0') + ans;
    }

    if (carry)
        ans = char(carry + '0') + ans;
    return ans;
}

bool isLeadingZero(string s) {
    return (s.size() > 1 && s[0] == '0');
}

bool isAdditiveNumberUtil(string num, int beg, int len1, int len2) {
    
    string s1 = num.substr(beg, len1);
    string s2 = num.substr(beg + len1, len2);
    
    if(isLeadingZero(s1) || isLeadingZero(s2))
        return false;
    
    string str_sum = string_sum(s1, s2);
    int sum_len = str_sum.size();
    
    if (sum_len > num.size() - len1 - len2 - beg)
        return false;
    
    string s3 = num.substr(beg + len1 + len2, str_sum.size()); 
    
    if(isLeadingZero(s3))
        return false;
    
    if(s3 == str_sum) {
                    
        if (beg + sum_len + len1 + len2 == num.size())
            return true;

        return isAdditiveNumberUtil(num, beg + len1, len2, str_sum.size());
    }
    else
        return false;
}

bool isAdditiveNumber(string num) {
    
    int n = num.size();
    
    for(int i =1; i<n; i++) {
        for (int j = 1; i + j < n; j++) {
            
            if(isAdditiveNumberUtil(num, 0, i, j))
                return true;
        }
    }
    return false;
}
};