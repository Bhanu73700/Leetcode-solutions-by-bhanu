class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
       int x = 0;
       bool hasnonzero = false;
       for(int num:nums){
        x^=num;
        if(num!=0) hasnonzero = true;
       } 
       if(x!=0) return nums.size();
       else if(!hasnonzero) return 0;
       else return nums.size()-1;
    }
};