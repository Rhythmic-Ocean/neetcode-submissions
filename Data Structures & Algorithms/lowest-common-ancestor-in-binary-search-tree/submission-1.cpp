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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       std::stack<TreeNode*> myStk {};
       myStk.push(root);
       while(!myStk.empty()){
        TreeNode* node = myStk.top();
        myStk.pop();
        if((node->val>= p->val&& node->val<= q->val) || (node->val<= p->val&& node->val>= q->val)){
            return node;
        }
        else if(node->val < p->val && node->val < q->val){
            myStk.push(node->right);
        }
        else{
            myStk.push(node->left);
        }
       } 
    }
};
