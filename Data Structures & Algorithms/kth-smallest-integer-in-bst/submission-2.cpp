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
    int kthSmallest(TreeNode* root, int k) {
       std::stack<TreeNode*> myStk {};
       myStk.push(root);
       TreeNode* curr = myStk.top();
       int i {};
       while(!myStk.empty() || curr){
        while(curr){
            myStk.push(curr);
            curr = curr->left;
        }
        i++;
        curr = myStk.top();
        if(i == k) return curr->val;
        myStk.pop();
        curr = curr->right;
       } 
       return -1;
    }
};
