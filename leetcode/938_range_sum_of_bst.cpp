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
    int result = 0;
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root->left != NULL){
            rangeSumBST(root->left, L, R);
        }
        
        if(root->val >= L && root->val <= R) result += root->val;
        
        if(root->right != NULL){
            rangeSumBST(root->right, L, R);
        }
        
        return result;
    }
};