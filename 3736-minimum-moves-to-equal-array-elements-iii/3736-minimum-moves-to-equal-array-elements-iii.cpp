class Solution {
public:
    int minMoves(vector<int>& nums) {
       int n = nums.size();
       sort(nums.begin(),nums.end());
       int ans = 0;
       for(int i=0;i<n;i++){
        int ele = nums[n-1] - nums[i];
        ans += ele;
       } 
       return ans;
    }
};