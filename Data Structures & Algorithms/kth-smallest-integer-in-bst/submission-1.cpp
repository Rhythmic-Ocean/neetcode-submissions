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
       std::vector<int> finalAns{};
       std::stack<TreeNode*> myStk {};
       myStk.push(root);
       TreeNode* curr = myStk.top();
       while(!myStk.empty() || curr){
        while(curr){
            myStk.push(curr);
            curr = curr->left;
        }
        curr = myStk.top();
        myStk.pop();
        finalAns.push_back(curr->val);
        curr = curr->right;
       } 
       return finalAns[k-1];
    }
};
