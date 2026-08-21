#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long getUpperBound(const vector<int>& coins, long long k)
    {
        return 1LL * coins[0] * k;
    }

    long long getLCM(long long a, long long b)
    {
        long long g = gcd(a, b);
        return a / g * b;
    }

    long long countAmounts(const vector<int>& coins, long long x)
    {
        int n = coins.size();
        long long result = 0;
        for (int mask = 1; mask < (1 << n); mask++)
        {
            long long lcm = 1;
            int bits = 0;
            bool overflow = false;
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    bits++;
                    lcm = getLCM(lcm, coins[i]);
                    if (lcm > x)
                    {
                        overflow = true;
                        break;
                    }
                }
            }
            if (overflow)
                continue;
            long long amount = x / lcm;
            if (bits % 2 == 1)
                result += amount;
            else
                result -= amount;
        }
        return result;
    }

    long long binarySearchAnswer(const vector<int>& coins, long long k)
    {
        long long low = 1;
        long long high = getUpperBound(coins, k);

        while (low < high)
        {
            long long mid = low + (high - low) / 2;
            long long count = countAmounts(coins, mid);
            if (count >= k)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
public:
    long long findKthSmallest(vector<int>& coins, int k)
    {
        sort(coins.begin(), coins.end());
        return binarySearchAnswer(coins, k);
    }
};