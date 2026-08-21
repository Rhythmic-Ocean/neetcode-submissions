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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int i {1};
        std::vector<std::pair<TreeNode*, int>> myStack {};
        myStack.push_back({root, i});
        int maxDepth {};
        while(!myStack.empty()){
           std::pair<TreeNode*, int> item = myStack.back();
           myStack.pop_back();
           TreeNode* node = item.first;
           int depth = item.second;
           maxDepth = max(maxDepth, depth);
           if(node->right) myStack.push_back({node->right, depth + 1});
           if(node->left) myStack.push_back({node->left, depth + 1});
        }
        return maxDepth;
    }
};
