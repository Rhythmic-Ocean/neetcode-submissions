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
       if(root == nullptr) return true;
       std::unordered_map<TreeNode*, int> myMap{};
       stack<TreeNode*> myStack {}; 
       myMap[nullptr] = 0;
       myStack.push(root);
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
            int leftHeight = myMap[node->left];
            int rightHeight = myMap[node->right];
            if(abs(leftHeight - rightHeight) >= 2) return false;
            int height = 1 + max(leftHeight, rightHeight);
            myMap[node] = height;
        }
       }
       return true;
    }
};
