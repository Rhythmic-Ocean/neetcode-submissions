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
        if(!root) return {};
        std::deque<TreeNode*> myQue {};
        std::vector<std::vector<int>> finAns {};
        myQue.push_back(root);
        while(!myQue.empty()){
            int lvlSize = myQue.size();
            std::vector<int> vec {};
            for(int i {}; i < lvlSize; ++i){
                TreeNode* node = myQue.front();
                vec.push_back(node->val);    
                myQue.pop_front();
                if(node->left) myQue.push_back(node->left);
                if(node->right) myQue.push_back(node->right);
            }
            finAns.push_back(std::move(vec));
        }
        return finAns;
    }
};
