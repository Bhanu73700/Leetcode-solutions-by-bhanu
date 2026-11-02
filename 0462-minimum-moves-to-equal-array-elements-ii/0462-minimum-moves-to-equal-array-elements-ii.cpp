class Solution {
public:
    int minMoves2(vector<int>& nums) {
      int n = nums.size();
      sort(nums.begin(),nums.end());
      int x = n/2;
      int sum = 0;
      for(int i=0;i<=x;i++){
        int ele = nums[x] - nums[i];
        sum += ele;
      }  
      int ans = 0;
      for(int i=x;i<n;i++){
        int b = nums[i] - nums[x];
        ans += b;
      }
      return sum + ans;
    }
};