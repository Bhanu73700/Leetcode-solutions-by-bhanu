class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                ans.push_back(nums[i-1]);
            }
        }
        int result = 0;
        for(int i=0;i<ans.size();i++){
            result += (ans[i]*ans[i]);
        }
        return result;
    }
};