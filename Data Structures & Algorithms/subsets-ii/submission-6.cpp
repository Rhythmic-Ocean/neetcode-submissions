class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<vector<int>> finalAns {};
       finalAns.reserve(1UL << nums.size());
       finalAns.push_back({});
       std::ranges::sort(nums);
       int startIndx {};
       for(auto i {0uz}; i < nums.size(); ++i){
        if(i > 0 && nums[i-1] != nums[i]) startIndx = 0;
        int curSize = finalAns.size();
        for(int j = startIndx;  j < curSize; ++j){
            vector new_vec = finalAns[j];
            new_vec.push_back(nums[i]);
            finalAns.push_back(new_vec);
        }
        startIndx = curSize;
       } 
       return finalAns;
    }
};
