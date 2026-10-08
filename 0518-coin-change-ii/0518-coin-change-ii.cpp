class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        const long long LIMIT = INT_MAX;

        vector<vector<long long>> t(
            n + 1, vector<long long>(amount + 1, 0)
        );

        // With 0 coins, only amount 0 can be formed.
        for (int i = 0; i <= n; i++) {
            t[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {

                // Don't take the current coin
                t[i][j] = t[i - 1][j];

                // Take the current coin
                if (coins[i - 1] <= j) {
                    t[i][j] = min(
                        LIMIT,
                        t[i][j] + t[i][j - coins[i - 1]]
                    );
                }
            }
        }

        return (int)t[n][amount];
    }
};