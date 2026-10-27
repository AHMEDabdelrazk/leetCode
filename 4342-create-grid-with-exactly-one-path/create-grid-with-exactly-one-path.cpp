class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;

        for(int i=0;i<m;i++){
            string a = "";
            for(int j=0;j<n;j++){
                if(j==0){
                    a+='.';
                }
                else if(i ==m-1){
                    a+='.';
                }
                else{
                    a+='#';
                }


            }
            ans.push_back(a);
        }
        return ans;
        
    }
};