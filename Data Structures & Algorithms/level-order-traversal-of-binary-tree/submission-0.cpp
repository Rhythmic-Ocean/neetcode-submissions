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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
       std::deque<pair<TreeNode*, int>> myQue {}; //node, depth
       int depth {1};
       std::vector<vector<int>> myVec {};
       myVec.push_back({root->val});
       if(root->left) myQue.push_back({root->left, 2}); 
       if(root->right) myQue.push_back({root->right, 2}); 
       while(!myQue.empty()){
        auto pNode = myQue.front();
        TreeNode* node = pNode.first;
        myQue.pop_front();
        if(myVec.size() == pNode.second){
            auto &vec = myVec.back();
            vec.push_back(pNode.first->val);
        }
        else{
            myVec.push_back({pNode.first->val});
        }
        if(node->left) myQue.push_back({node->left, pNode.second + 1});
        if(node->right) myQue.push_back({node->right, pNode.second + 1}); 
       } 
       return myVec;
    }
};
