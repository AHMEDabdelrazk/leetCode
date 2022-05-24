class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>h = heights; int ans=0;
        stack<pair<int,int>> S; S.push(make_pair(0,h[0]));
        for(int i=1;i<h.size();i++){
            if(S.top().second<=h[i])
                S.push(make_pair(i,h[i]));
            else{
                int c=1 , I=i;
                while(!S.empty() && S.top().second>=h[i]){
                    pair<int,int> p = S.top(); S.pop();
                    ans = max(ans,(i-p.first)*p.second);
                    c++,I=p.first;
                }
                cout<<I<<" "<<h[i]<<" \ ";
                S.push(make_pair(I,h[i]));
            }
        }
        
        int j = h.size() ;
        //if(!S.empty()) j=S.top().first+1;
        while(!S.empty()){
            ans=max(ans,S.top().second*(j-S.top().first));
            S.pop();
        }
        return ans ; 
    }
};