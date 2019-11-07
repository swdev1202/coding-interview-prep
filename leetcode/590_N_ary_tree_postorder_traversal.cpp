/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    vector<int> solution;
public:
    vector<int> postorder(Node* root) {
        
        /*
        // recursive
        
        if(!root) return solution;
        
        // child check
        if(root->children.empty()){
            solution.push_back(root->val);
            return solution;
        }
        
        // children iteratation
        
        for(vector<Node*>::iterator it = root->children.begin(); it != root->children.end(); ++it){
            postorder(*it);
        }
        
        solution.push_back(root->val);
        
        
        return solution;
        */
        
        // iterative
        if(!root) return {};
        
        vector<int> result;
        stack<Node*> node_stack;
        
        node_stack.push(root);
        
        while(!node_stack.empty())
        {
            if(root->children.empty())
            {
                
            }
        }
    }
};