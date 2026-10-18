
class Solution {
public:
    const int MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

    int nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n - r) r = n - r;

        long long numerator = 1;
        long long denominator = 1;

        for (int i = 0; i < r; ++i) {
            numerator = (numerator * (n - i)) % MOD;
            denominator = (denominator * (i + 1)) % MOD;
        }

        return (numerator * modInverse(denominator)) % MOD;
    }

    int countInterleavings(const vector<int>& A, const vector<int>& B) {
        return nCr(A.size() + B.size(), A.size());
    }

    int solve(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        int root = nums[0];
        vector<int> leftTree, rightTree;

        for (int i = 1; i < n; i++) {
            if (nums[i] < root)
                leftTree.push_back(nums[i]);
            else
                rightTree.push_back(nums[i]);
        }

        long long leftWays = solve(leftTree);
        long long rightWays = solve(rightTree);

        long long interleavings =
            countInterleavings(leftTree, rightTree);

        return (leftWays * rightWays % MOD) * interleavings % MOD;
    }

    int numOfWays(vector<int>& nums) {
        return (solve(nums) - 1 + MOD) % MOD;
    }
};
