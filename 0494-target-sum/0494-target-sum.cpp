class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
       int sum = 0;
       for(int x:nums){
        sum+=x;
       } 
       if(abs(target)>sum) return 0;
       if((sum+target)%2!=0) return 0;

       int need = (sum+target)/2;

       vector<int> dp(need+1,0);
       dp[0] = 1;

       for(int x:nums){
        for(int j=need;j>=x;j--){
            dp[j] += dp[j-x];
        }
       }
       return dp[need];
    }
};