
class Solution {
public:
TreeNode* insertIntoBST(TreeNode* root, int val) {
      if(root==NULL) return new TreeNode(val);
      if(root->val<val){
        if(root->right==NULL){
            root->right=new TreeNode(val);
        } else{
           insertIntoBST(root->right,val); 
        }
      } else{
        if(root->left==NULL){
            root->left=new TreeNode(val);
        } else{
            insertIntoBST(root->left,val);
        }
      }
      return root;  
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
       TreeNode* root = new TreeNode(pre[0]);
       for(int i=1;i<pre.size();i++){
        insertIntoBST(root,pre[i]);
       } 
       return root;
    }
};