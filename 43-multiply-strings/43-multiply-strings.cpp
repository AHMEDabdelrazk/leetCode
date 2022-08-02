class Solution {
public:
    string multiply(string num1, string num2) {
        
        if (num1 == "0" || num2 == "0") return "0";
        
        int n1 = num1.size();
        int n2 = num2.size();
        
        vector<int> res(n1+n2, 0);
        
        int i = n2 - 1;
        int powerFactor = 0;
        
        while(i >= 0) {
            int ival = num2[i] - '0';
            
            int carry = 0;
            int j = n1 - 1;
            int k = res.size() - 1 - powerFactor;
            
            while(j >= 0 || carry != 0) {
                int jval = j >= 0 ? num1[j] - '0' : 0;
                
                int prod = (ival * jval) + carry + res[k];
                res[k] = prod % 10;
                carry = prod / 10;
                k--;
                
                j--;
            }
            
            powerFactor++;
            i--;
        }
        
        bool flag = false;
        string ans = "";
        
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == 0 && flag == false) {
                continue;
            } else {
                flag = true;
                ans += res[i] + '0';
            }
        }
        
        return ans;
    }
};