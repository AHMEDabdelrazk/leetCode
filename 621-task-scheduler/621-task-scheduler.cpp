class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> hash;
        for (auto ch : tasks) hash[ch]++;
        
        int maxv = 0, cnt = 0;
        for (auto& [k, v] : hash) maxv = max(maxv, v);
        for (auto& [k, v] : hash) {
            if (maxv == v) cnt++;
        }
        
        return max(int(tasks.size()), (maxv - 1) * (n + 1) + cnt);
    }
};