class Solution {
    vector<vector<int>> finalAns {};
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> exclude {};
        int height = nums.size();
       vector<int> new_vec {};
       for(int i {}; i < nums.size(); ++i){
            new_vec.push_back(nums[i]);
            exclude.insert(i);
            backtracking(nums, i, new_vec, exclude);
            exclude.erase(i);
            new_vec.pop_back();
       } 
       return finalAns;
    }

    void backtracking(vector<int>& nums, int indx, vector<int>& new_vec, unordered_set<int>& exclude){
        if(nums.size() == exclude.size()) {
            finalAns.push_back(new_vec);
            return;
        }
        for(int i {}; i < nums.size(); ++i){
            if(exclude.contains(i)) continue;
            new_vec.push_back(nums[i]);
            exclude.insert(i);
            backtracking(nums, i, new_vec, exclude);
            exclude.erase(i);
            new_vec.pop_back();
        } 
    }
};
