class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(auto i {0}; i < nums.size(); ++i){
            for(auto j {0}; j < nums.size(); ++j){
                if((nums[i] + nums[j]) == target){
                    if(i == j) continue;
                    return {min(i, j), max(i, j)};
                }
            }
        }
    }
};
