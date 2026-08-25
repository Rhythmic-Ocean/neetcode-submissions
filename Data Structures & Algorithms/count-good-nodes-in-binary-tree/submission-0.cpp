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
       stack<int> monPut {};
       stack<TreeNode*> myStk {};
       unordered_set<TreeNode*> um{};
       int num {};
       um.insert(root);
       myStk.push(root);
       monPut.push(root->val);
       
       while(!myStk.empty()){
        TreeNode* node = myStk.top();
        if(node->left && um.find(node->left) == um.end()){
            myStk.push(node->left);
            um.insert(node->left);
            if(node->left->val >= monPut.top()){
                monPut.push(node->left->val);
            }
        }
        else if(node->right && um.find(node->right) == um.end()){
            myStk.push(node->right);
            um.insert(node->right);
            if(node->right->val >= monPut.top()){
                monPut.push(node->right->val);
            }
        }
        else{
            TreeNode* item = myStk.top();
            myStk.pop();
            if(item->val >= monPut.top()){
                num++;
            }
            if(item->val == monPut.top()){
                monPut.pop();
            }
        }
       }
       return num;

    }
};
