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
       std::unordered_map<TreeNode*, pair<int, int>> myMap {};
       int maxDiam {};
       stack<TreeNode*> myStack {};
       myStack.push(root);
       myMap.insert({root, {1, -1}});
       while(!myStack.empty()){
        TreeNode* node = myStack.top();
        if(node->left && myMap.find(node->left) == myMap.end()){
            myStack.push(node->left);
        }
        else if(node->right && myMap.find(node->right) == myMap.end()){
            myStack.push(node->right);
        }
        else{
            myStack.pop();
            auto[leftHeight, leftDiam] = myMap[node->left];
            auto[rightHeight, rightDiam] = myMap[node->right];
            int height = 1 + max(leftHeight, rightHeight);
            int diam = leftHeight + rightHeight;
            myMap[node]= {height, diam};
            maxDiam = max(diam, maxDiam);
        }
        
       }
       return maxDiam;
    }
};
