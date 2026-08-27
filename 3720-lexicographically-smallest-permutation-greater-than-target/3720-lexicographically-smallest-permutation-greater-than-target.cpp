class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        int n = s.size();

        // Try to make the answer equal to target
        // for as long as possible.
        for (int i = n - 1; i >= 0; i--) {

            // Rebuild counts of characters available
            // after matching target[0...i-1].
            vector<int> temp = cnt;

            bool possible = true;

            for (int j = 0; j < i; j++) {
                if (--temp[target[j] - 'a'] < 0) {
                    possible = false;
                    break;
                }
            }

            if (!possible)
                continue;

            // At position i, choose the smallest character
            // strictly greater than target[i].
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (temp[c] > 0) {
                    string ans = target.substr(0, i);

                    ans += char('a' + c);
                    temp[c]--;

                    // Put remaining characters in sorted order.
                    for (int x = 0; x < 26; x++) {
                        ans += string(temp[x], char('a' + x));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};