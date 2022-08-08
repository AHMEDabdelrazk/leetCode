class Solution {
public:

bool isPossibleToReach(vector<int> &dist, int mid, double hour){
    
    int n = dist.size();
    double total_time = 0.0;
    
    for(int i=0; i<n-1; i++){
        
        
        if( dist[i]*1.0/mid > dist[i]/mid){
            
            total_time += dist[i]/mid + 1;
        }
        else{
            total_time += dist[i]/mid;
        }
        
    }
    
    
    total_time += dist[n-1]*1.0/mid;
    
    
    return total_time <= hour;
    
    // return 1;
    
    
    
}

int minSpeedOnTime(vector<int>& dist, double hour) {
    
    int low = 1;
    int high = 1e9;
    
    
    while(low <= high){
        
        int mid = (low+high)>>1;
        
        if(isPossibleToReach(dist, mid, hour)){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
        
    }
    
    
    if(low > 1e9) return -1;
    
    return low;
    
}
};