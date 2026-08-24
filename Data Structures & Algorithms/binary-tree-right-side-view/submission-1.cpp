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
    vector<int> rightSideView(TreeNode* root) {
       if(!root) return {};
       queue<TreeNode*> myQue{};
       vector<int> myVec {};
       myQue.push(root);
       while(!myQue.empty()){
        int lvlSize = myQue.size();
        TreeNode* node {myQue.front()};
        for(int i {}; i < lvlSize; ++i){
            node = myQue.front();
            myQue.pop();
            if(node->left) myQue.push(node->left);
            if(node->right) myQue.push(node->right);
        }
        myVec.push_back(node->val);
       }
       return myVec;
    }
};
