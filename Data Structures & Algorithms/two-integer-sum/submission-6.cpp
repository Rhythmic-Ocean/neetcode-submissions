class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> mymap {};
        int difference {};
        for(auto i {0}; i < nums.size(); ++i){
            difference = target - nums[i];
            auto myit = mymap.find(difference);
            if(myit != mymap.end()){
                return {myit->second, i};
            }
            else{
                mymap.emplace(nums[i], i);
            }
        }
        return {};
    }
};
