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
    int diameterOfBinaryTree(TreeNode* root) {
        int depth {};
        maxDiam(root, depth);
        return depth;
         
    }
    int maxDiam(TreeNode* myNode, int& dp){
        if(myNode == nullptr) return 0;
        int left {};
        int right {};
        if(myNode->left) left = maxDiam(myNode->left, dp);
        if(myNode->right) right = maxDiam(myNode->right, dp);
        int dpth = max(left, right);
        dp = max(dp, left + right);
        return 1 + dpth;
    }
};
