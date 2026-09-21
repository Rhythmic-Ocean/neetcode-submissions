class Solution {
    vector<vector<int>> finalAns {};
public:
    vector<vector<int>> permute(vector<int>& nums) {
       unsigned int mask {};
       int height = nums.size();
       vector<int> new_vec {};
       for(int i {}; i < nums.size(); ++i){
            new_vec.push_back(nums[i]);
            mask |= (1 << (i));
            backtracking(nums, i, new_vec, mask);
            mask &= ~(1 << (i));
            new_vec.pop_back();
       } 
       return finalAns;
    }

    void backtracking(vector<int>& nums, int indx, vector<int>& new_vec, unsigned int mask){
        if(mask == (1 << nums.size()) - 1) {
            finalAns.push_back(new_vec);
            return;
        }
        for(int i {}; i < nums.size(); ++i){
            if(mask & (1 << (i))) continue;
            new_vec.push_back(nums[i]);
            mask |= (1 << (i));
            backtracking(nums, i, new_vec, mask);
            mask &= ~(1 << (i));
            new_vec.pop_back();
        } 
    }
};
