class Solution {
public:
    struct Node {
        long long score;
        vector<int> ids;
    };

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {intervals[i][0], intervals[i][1],
                    intervals[i][2], i};
        }

        sort(a.begin(), a.end());

        vector<long long> starts(n);
        for (int i = 0; i < n; i++)
            starts[i] = a[i][0];

        vector<vector<Node>> dp(n + 1, vector<Node>(5));

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {

                // Skip current interval
                Node best = dp[i + 1][k];

                // Take current interval
                long long r = a[i][1];
                long long w = a[i][2];
                int id = a[i][3];

                // First interval whose start > r
                int j = upper_bound(starts.begin(), starts.end(), r)
                        - starts.begin();

                Node take = dp[j][k - 1];
                take.score += w;
                take.ids.push_back(id);

                sort(take.ids.begin(), take.ids.end());

                if (take.score > best.score ||
                    (take.score == best.score && take.ids < best.ids)) {
                    best = take;
                }

                dp[i][k] = best;
            }
        }

        return dp[0][4].ids;
    }
};