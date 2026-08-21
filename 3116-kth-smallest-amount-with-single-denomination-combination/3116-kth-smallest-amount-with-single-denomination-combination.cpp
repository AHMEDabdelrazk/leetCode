#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    // Step 2:
    // Calculate the binary search range.
    long long getUpperBound(const vector<int>& coins, long long k)
    {
        return 1LL * coins[0] * k;
    }


    // Helper for Step 4:
    // Calculate LCM safely.
    long long getLCM(long long a, long long b)
    {
        long long g = gcd(a, b);

        // Prevent overflow
        //if (a > LLONG_MAX / (b / g))
          //  return LLONG_MAX;

        return a / g * b;
    }


    // Step 4:
    // Inclusion-Exclusion.
    //
    // For every subset of coins:
    // odd number of coins  -> +
    // even number of coins -> -
    long long countUsingInclusionExclusion(
        const vector<int>& coins,
        long long x)
    {
        int n = coins.size();
        long long result = 0;

        // Every subset of coins
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


    // Step 3:
    // How many distinct valid amounts are <= x?
    long long countAmounts(
        const vector<int>& coins,
        long long x)
    {
        return countUsingInclusionExclusion(coins, x);
    }


    // Step 5:
    // Binary search for the smallest x
    // where countAmounts(x) >= k.
    long long binarySearchAnswer(
        const vector<int>& coins,
        long long k)
    {
        long long low = 1;
        long long high = getUpperBound(coins, k);

        while (low < high)
        {
            long long mid = low + (high - low) / 2;

            long long count = countAmounts(coins, mid);

            if (count >= k)
            {
                // mid could be the answer
                high = mid;
            }
            else
            {
                // mid is too small
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