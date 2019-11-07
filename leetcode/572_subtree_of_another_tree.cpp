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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t) return 1;
        if(!s || !t) return 0;
        
        if(s->val == t->val && is_tree_same(s,t)){
            return 1;
        }
        else{
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        }
        
    }
    
    bool is_tree_same(TreeNode* a, TreeNode* b){
        if(!a && !b) return 1;
        if(!a || !b) return 0;
        
        return (a->val == b->val) && is_tree_same(a->left, b->left) && is_tree_same(a->right, b->right);
    }
};