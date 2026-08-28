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
    long mxx {INT_MIN};
    long mx_node {INT_MIN};
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        long n = dfs(root);
        if(mxx == 0) return min(mxx, mx_node);
        return mxx;
    }
    long dfs(TreeNode* root){
        if(!root) return INT_MIN;
        mx_node = max(mx_node, static_cast<long>(root->val));
        long lft = dfs(root->left);
        long rght = dfs(root->right);
        long mx = max(lft, max(rght, max(lft + rght + root->val, max(static_cast<long>(root->val), max(lft + root->val, max(rght + root->val, 0L))))));
        mxx = max(mx, mxx);
    return max(static_cast<long>(root->val),
               max(lft + root->val, rght + root->val));
    }
};
