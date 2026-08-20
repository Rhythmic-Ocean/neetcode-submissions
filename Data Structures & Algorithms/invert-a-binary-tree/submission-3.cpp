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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        std::vector<TreeNode*> myStack {};
        myStack.push_back(root);
        while(!myStack.empty()){
            TreeNode* temp = myStack.back();
            myStack.pop_back();
            TreeNode* temp2 = temp->left;
            temp->left = temp->right;
            temp->right = temp2;
            if(temp->right) myStack.push_back(temp->right);
            if(temp->left) myStack.push_back(temp->left);
        }
        return root;
    }
};
