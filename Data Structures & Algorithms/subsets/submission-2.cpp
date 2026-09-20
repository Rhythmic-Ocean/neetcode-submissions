class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> finalAns {};
        finalAns.reserve(1 << nums.size());
        finalAns.push_back({});
        for(auto num: nums){
            int n = finalAns.size();
            for(int i {}; i < n; ++i){
                vector<int> new_vec = finalAns[i];
                new_vec.push_back(num);
                finalAns.push_back(std::move(new_vec));
            }
        }
        return finalAns;
    }
};
