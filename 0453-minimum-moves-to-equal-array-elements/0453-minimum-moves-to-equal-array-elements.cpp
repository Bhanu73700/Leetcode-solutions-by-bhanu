class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ele = *min_element(nums.begin(),nums.end());
        int sum = 0;
        for(int i=0;i<n;i++){
            int bha = nums[i] - ele;
            sum += bha;
        }
        return sum;
    }
};