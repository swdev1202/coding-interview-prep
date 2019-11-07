/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        /* // recursive solution
        if(root == NULL || val == root->val) return root;
        
        return (val < root->val)? searchBST(root->left, val) : searchBST(root->right, val);
        */
        
        // iterative solution
        while(root != NULL)
        {
            // if you find it, you are done.
            if(root->val == val) return root;
            
            root = (val < root->val)? root->left : root->right;
        }
        
        return NULL;
    }
};