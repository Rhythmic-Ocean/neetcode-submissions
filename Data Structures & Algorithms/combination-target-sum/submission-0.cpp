class Solution {
    vector<vector<int>> finalAns {};
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        for(int i {}; i < nums.size(); ++i){
            vector<int> new_vec {nums[i]};
            doSum(nums[i], nums, target, new_vec, i);
        }
        return finalAns;
    }

    void doSum(int sum, vector<int>& nums, int target, vector<int>& cur_vec, int indx){
        if(sum == target){
            finalAns.push_back(std::move(cur_vec));
            return;
        }
        if(sum > target) return;
        for(int i {indx}; i < nums.size(); ++i){
            auto new_vec = cur_vec;
            new_vec.push_back(nums[i]);
            doSum(sum+nums[i], nums, target, new_vec, i);
        }
    }
};
