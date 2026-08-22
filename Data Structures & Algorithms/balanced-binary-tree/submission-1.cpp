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
    bool isBalanced(TreeNode* root) {
        if(depth(root) == -1)
            return false;
        return true;
    }
    int depth(TreeNode* root){
        if(!root) return 0;
        int leftHeight = depth(root->left);
        int rightHeight = depth(root->right);
        if(leftHeight == -1 || rightHeight == -1)
            return -1;
        else if(abs(leftHeight - rightHeight) > 1)
            return -1;
        return 1 + max(leftHeight, rightHeight);
    }
};
