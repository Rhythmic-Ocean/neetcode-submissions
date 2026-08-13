class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> mymap {};
        int difference {};
        for(auto i {0}; i < nums.size(); ++i){
            difference = target - nums[i];
            if(mymap.contains(difference)){
                return {mymap[difference], i};
            }
            else{
                mymap.insert({nums[i], i});
            }
        }
    }
};
