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
    int goodNodes(TreeNode* root) {
        int count {};
        dfs(root, INT_MIN, count);
        return count;

    }
    void dfs(TreeNode* node, int maxCount, int& count){
        if(!node) return;
        if(node->val>= maxCount){
            count++;
            maxCount = node->val;
        }
        dfs(node->left, maxCount, count);
        dfs(node->right, maxCount, count);
    }
};
