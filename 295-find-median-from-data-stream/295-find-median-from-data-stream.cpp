class MedianFinder {
public:
    priority_queue<int>ma;
    priority_queue<int, vector<int>, greater<int>>mi;
    MedianFinder() {        
    }
    
    void addNum(int num) {
        if (ma.size()==0){
            ma.push(num);
            return;
        }
        if (ma.size()>mi.size()){ //ODD CASE
            if (num<ma.top()){
                mi.push(ma.top());
                ma.pop();
                ma.push(num);
            }else{
                mi.push(num);
            }
        }else{                    // EVEN CASE
            if (num<ma.top()){ 
                ma.push(num);
            }else{
                mi.push(num);
                ma.push(mi.top());
                mi.pop();
            }
        }
    }
    double findMedian() {
        if (ma.size()==mi.size()){
            return ((double) (ma.top()+mi.top())/2);
        }else{
            return ((double)ma.top());
        }   
    }
};