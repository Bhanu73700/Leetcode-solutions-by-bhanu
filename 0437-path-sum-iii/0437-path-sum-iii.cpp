
class Solution {
public:
     void helper(TreeNode* root,long long sum,int& count){
        if(root==NULL) return;
            if((long long)root->val==sum){
               count++;
            }
        
        helper(root->left,sum-(long long)(root->val),count);
        helper(root->right,sum-(long long)(root->val),count);
    }
    int pathSum(TreeNode* root, int targetsum) {
        if(root==NULL) return 0;
        int count = 0;
        helper(root,(long long)(targetsum),count);
        count+=(pathSum(root->left,targetsum)+pathSum(root->right,targetsum));
        return count;
    }
};