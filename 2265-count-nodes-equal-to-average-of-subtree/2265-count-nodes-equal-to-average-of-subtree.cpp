
class Solution {
public:
    int sum(TreeNode* root){
        if(root==NULL) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }
    int size(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + size(root->left) + size(root->right);
    }
    void solve(TreeNode* root, int &count){
        if(root==NULL) return;
         int avg = sum(root)/size(root); 
         if(root->val == avg) count++;
         solve(root->left,count);
         solve(root->right,count);
    }
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        solve(root,count);
        return count;
    }
};