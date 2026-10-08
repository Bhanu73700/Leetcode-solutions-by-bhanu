class Solution {
public:
    int change(int amount, vector<int>& coins) {
        const long long LIMIT = INT_MAX;

        vector<long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] = min(LIMIT, dp[j] + dp[j - coin]);
            }
        }

        return (int)dp[amount];
    }
};