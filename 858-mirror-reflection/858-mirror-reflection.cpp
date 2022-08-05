class Solution {
public:

int mirrorReflection(int p, int q) {
    int c=p;
    int t=1;
    while(p%q!=0){
        p+=c;
        t++;
    }
    if(t%2!=0){
        if((p/q)%2==0)
        return 2;
        else
        return 1;
    }
   return 0;
}
};