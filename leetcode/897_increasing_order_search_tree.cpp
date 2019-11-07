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
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL) return NULL;
        
        if(root->left != NULL){
            increasingBST(root->left);
        }
        
        if(result == NULL){
            result = new TreeNode(root->val);
            itr = result;
        }
        else{
            itr->right = new TreeNode(root->val);
            itr = itr->right;
        }
        
        
        if(root->right != NULL){
            increasingBST(root->right);
        }
        
        return result;
    }
};