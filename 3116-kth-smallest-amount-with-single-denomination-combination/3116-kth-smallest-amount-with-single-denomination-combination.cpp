class Solution {
public:
    long long count(long long x, vector<int>& coins) {
        long long ans = 0;
        int n = coins.size();

        for (int mask = 1; mask < (1 << n); mask++) {
            long long lcm = 1;
            bool overflow = false;
            int bits = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    long long g = std::gcd(lcm, (long long)coins[i]);

                    if (lcm > x / (coins[i] / g)) {
                        overflow = true;
                        break;
                    }

                    lcm = lcm / g * coins[i];
                }
            }

            if (overflow || lcm > x)
                continue;

            if (bits % 2)
                ans += x / lcm;
            else
                ans -= x / lcm;
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (count(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};