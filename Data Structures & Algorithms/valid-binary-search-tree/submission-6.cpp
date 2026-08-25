/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    struct StackItem{
        TreeNode* nde {};
        int mn {};
        int mx {};
    };
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        stack<StackItem> myStk {};
        myStk.push({root, INT_MIN, INT_MAX});
        while(!myStk.empty()){
            auto[node, m, x] = myStk.top();
            myStk.pop();
            if(node->val >= x || node->val <= m) return false;
            int mini = max(m, node->val);
            int maxi = min(x, node->val);
            if(node->right) myStk.push({node->right, mini, x});
            if(node->left) myStk.push({node->left, m, maxi});
        } 
        return true;
    }
};
