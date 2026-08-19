class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> mp;

        for (auto &seat : reservedSeats) {
            mp[seat[0]].push_back(seat[1]);
        }

        int ans = 2 * n;

        for (auto &[row, seats] : mp) {
            bool left = true;    // 2,3,4,5
            bool middle = true;  // 4,5,6,7
            bool right = true;   // 6,7,8,9

            for (int s : seats) {
                if (s >= 2 && s <= 5)
                    left = false;

                if (s >= 4 && s <= 7)
                    middle = false;

                if (s >= 6 && s <= 9)
                    right = false;
            }

            if (left && right)
                ans -= 0;
            else if (left || middle || right)
                ans -= 1;
            else
                ans -= 2;
        }

        return ans;
    }
};