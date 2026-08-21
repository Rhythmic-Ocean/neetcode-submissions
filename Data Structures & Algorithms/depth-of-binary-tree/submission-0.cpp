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
        std::vector<TreeNode*> myStack {};
        myStack.push_back(root);
        int maxDepth {1};
        int curDepth {1};
        while(!myStack.empty()){
            TreeNode* temp = myStack.back();
            if(!temp->right && !temp->left){
                myStack.pop_back();
                TreeNode* temp1 = myStack.back();
                //popping immediate parents and looking for siblings
                while(myStack.size() && (temp1->left == temp || temp1->right == temp)){
                    temp = myStack.back();
                    myStack.pop_back();
                    if(!myStack.empty())
                        temp1 = myStack.back();
                    curDepth--;
                }
                temp = temp1;
                continue;
            }
            if(temp->right) myStack.push_back(temp->right);
            if(temp->left) myStack.push_back(temp->left);
            curDepth++;
            if(maxDepth < curDepth) maxDepth = curDepth;
        }
        return maxDepth;
    }
};
