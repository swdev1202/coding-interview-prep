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
    TreeNode* invertTree(TreeNode* root) {

        if(root == NULL) return NULL;
        
        if(root->left != NULL || root->right != NULL)
        {
            // swap
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        
        if(root->left != NULL)
        {
            invertTree(root->left);
        }
        
        if(root->right != NULL)
        {
            invertTree(root->right);
        }
        
        return root;
    }
};