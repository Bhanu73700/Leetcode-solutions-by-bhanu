class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> presum(n+1,0);

        for(int i=0;i<n;i++){
            presum[i+1] = presum[i] + nums[i];
        }
        int ans = INT_MAX;
        for(int len=l;len<=r;len++){
            for(int i=len;i<=n;i++){
                int sum = presum[i] - presum[i-len];
            
            if(sum>0) ans = min(ans,sum);
            }
        }
        return ans == INT_MAX? -1 : ans; 
    }
};