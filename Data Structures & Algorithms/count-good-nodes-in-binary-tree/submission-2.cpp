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
       if(!root) return 0;
       std::stack<pair<TreeNode*, int>> myStk {}; //node, maxCount
       int num{};
       myStk.push(make_pair(root, root->val));
       while(!myStk.empty()){
        auto[node, maxCount] = myStk.top();
        myStk.pop();
        if(node->val >= maxCount) num++;
        int mC = max(node->val, maxCount);
        if(node->left) myStk.push({node->left, mC});
        if(node->right) myStk.push({node->right, mC});
       }
       return num;
    }
};
