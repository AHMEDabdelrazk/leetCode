class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) 
    {
        int n = chalk.size();
        long long int total_chalks = 0;
        for(int i=0; i<n; i++)
        {
            total_chalks = total_chalks+chalk[i];
        }
        k = k%total_chalks;
        
        int idx = 0;
        while(chalk[idx]<=k)
        {
            k = k-chalk[idx];
            idx++;
            idx = idx%n;
        }
        return idx;
    }
};