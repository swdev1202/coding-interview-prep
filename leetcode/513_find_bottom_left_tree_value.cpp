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
    int findBottomLeftValue(TreeNode* root) {
        std::queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty()){
            root = q.front();
            q.pop();
            
            if(root->right != NULL){
                q.push(root->right);
            }
            
            if(root->left != NULL){
                q.push(root->left);
            }
        }
        
        return root->val;
    }
};