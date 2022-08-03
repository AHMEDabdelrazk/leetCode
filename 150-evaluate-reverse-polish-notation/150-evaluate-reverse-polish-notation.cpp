class Solution {
public:
    int solve(int q,int p,string a){
        if(a=="+") return (q)+(p);
        if(a=="-") return (q)-(p);
        if(a=="*") return (q)*(p);
        return (q)/(p);
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto a: tokens){
            if(a=="+" || a=="-" || a=="*" || a=="/"){
                int p = st.top();
                st.pop();
                int q = st.top();
                st.pop();
                int calc = solve(q,p,a);
                st.push(calc);
            }else{
                st.push(stoi(a));
            }
        }
        return st.top();
    }
};