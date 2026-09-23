class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<vector<int>> finalAns {};
       finalAns.reserve(1 << nums.size());
       int k {}; //measures hw many new vectors did the last one put in
       finalAns.push_back({});
       std::ranges::sort(nums);
       int n {};
       for(auto i {0uz}; i < nums.size(); ++i){
        n = finalAns.size();
        if (i > 0 && nums[i - 1] == nums[i]) n = k;
        size_t last = finalAns.size() - 1;
        k = 0;
        for(int j = 0;  j < n; ++j){
            ++k;
            vector new_vec = finalAns[last- j];
            new_vec.push_back(nums[i]);
            finalAns.push_back(new_vec);
        }
       } 
       return finalAns;
    }
};
