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
public:
    bool isValidBST(TreeNode* root) {
       if(!dfs(root, INT_MIN, INT_MAX)) return false;
       return true; 
    }
    bool dfs(TreeNode* root, int mn, int mx){
        if(!root) return true;
        int mini = max(mn, root->val);
        int maxi = min(mx, root->val);
        if(!dfs(root->left, mn, maxi)) return false;
        if(!dfs(root->right, mini, mx)) return false;
        if(root->val <= mn || root->val >=mx) return false;
        return true;
    }
};
