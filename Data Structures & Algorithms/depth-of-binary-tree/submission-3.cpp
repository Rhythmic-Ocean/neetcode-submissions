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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        std::deque<TreeNode*> myQueue {};    
        myQueue.push_back(root);
        int depth {};
        while(!myQueue.empty()){
            int size = myQueue.size();
            for(int i {}; i < size; ++i){
                TreeNode* myNode = myQueue.front();
                myQueue.pop_front();
                if(myNode->left) myQueue.push_back(myNode->left);
                if(myNode->right) myQueue.push_back(myNode->right);
            }
            ++depth;
        }
        return depth;
    }
};
