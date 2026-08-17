class Solution {
public:
    TreeNode* iop(TreeNode* root) {
        TreeNode* pred = root->left;

        while (pred->right != NULL) {
            pred = pred->right;
        }

        return pred;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;

        // First find the node
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // Node found

            // Case 1: No child
            if (root->left == NULL && root->right == NULL)
                return NULL;

            // Case 2: Only right child
            if (root->left == NULL)
                return root->right;

            // Case 2: Only left child
            if (root->right == NULL)
                return root->left;

            // Case 3: Two children
            TreeNode* pred = iop(root);
            root->val = pred->val;

            root->left = deleteNode(root->left, pred->val);
        }

        return root;
    }
};