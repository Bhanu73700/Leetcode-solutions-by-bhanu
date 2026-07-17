class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> cnt(mx + 1, 0);
        for (int x : nums) cnt[x]++;

        vector<long long> cntG(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {
            long long c = 0;

            for (int j = g; j <= mx; j += g) {
                c += cnt[j];
                cntG[g] -= cntG[j];
            }

            cntG[g] += c * (c - 1) / 2;
        }

        vector<long long> pref(mx + 1, 0);
        for (int i = 1; i <= mx; i++)
            pref[i] = pref[i - 1] + cntG[i];

        vector<int> ans;

        for (long long q : queries) {
            int l = 1, r = mx;

            while (l < r) {
                int mid = l + (r - l) / 2;
                if (pref[mid] > q)
                    r = mid;
                else
                    l = mid + 1;
            }

            ans.push_back(l);
        }

        return ans;
    }
};