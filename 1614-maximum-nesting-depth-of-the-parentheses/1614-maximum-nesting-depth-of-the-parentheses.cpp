class Solution {
public:
    int maxDepth(string s) {
        int k = 0;
        vector<int> ans;
        for(char c:s){
            if(c=='('){
                k++;
                ans.push_back(k);
            } else if(c==')'){
                k--;
            }
        }
        if(ans.empty()) return 0;
        int max = *max_element(ans.begin(),ans.end());
        return max;
    }
};