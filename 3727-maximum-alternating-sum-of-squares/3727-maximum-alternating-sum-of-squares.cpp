class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr;
        for(int i=0;i<n;i++){
            long long sq = nums[i]*nums[i];
            arr.push_back(sq);
        }
        sort(arr.begin(),arr.end());
        int x = arr.size();
        int k = x/2;
        long long leftsum = 0;
        long long rightsum = 0;
        for(int i=0;i<k;i++){
            leftsum += arr[i];
        }
        for(int i=k;i<n;i++){
            rightsum += arr[i];
        }
        return rightsum - leftsum;
    }
};