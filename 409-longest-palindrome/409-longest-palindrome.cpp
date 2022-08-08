
class Solution {
public:
    int longestPalindrome(string s) {
        int arr[123]={0};
        for(int i = 0; i < s.size(); i++){
            arr[s[i]]++;
        }
        int ans = 0;
        int flag = 0;
        for(int i = 65; i < 123 ; i++){
            if(arr[i]%2 == 0){
                ans += arr[i];
            }
            else{
                ans += arr[i]-1;
                flag = 1;                
            }
        }
        ans += flag;
        return ans;
    }
};