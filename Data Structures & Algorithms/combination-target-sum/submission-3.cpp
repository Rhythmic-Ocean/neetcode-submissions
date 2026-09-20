class Solution {
    vector<vector<int>> finalAns {};
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::ranges::sort(nums);
        vector<int> new_vec {};
        for(int i {}; i < nums.size(); ++i){
            if(nums[i] > target) break;
            new_vec.push_back(nums[i]);
            doSum(nums[i], nums, target, new_vec, i);
            new_vec.pop_back();
        }
        return finalAns;
    }

    void doSum(int sum, vector<int>& nums, int target, vector<int>& cur_vec, int indx){
        if(sum == target){
            finalAns.push_back(cur_vec);
            return ;
        }
        for(int i {indx}; i < nums.size(); ++i){
            if(sum + nums[i] > target) return;
            cur_vec.push_back(nums[i]);
            doSum(sum+nums[i], nums, target, cur_vec, i);
            cur_vec.pop_back();
        }
        return ;
    }
};
