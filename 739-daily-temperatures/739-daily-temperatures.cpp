class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int>s;
        for(int i=0;i<t.size();i++){
            while(!s.empty() && t[s.top()]<t[i]){
                t[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            t[s.top()]=0;
            s.pop();
        }
        return t;
    }
};