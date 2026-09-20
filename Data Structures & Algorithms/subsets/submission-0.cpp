class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> finalAns {};
        finalAns.push_back({});
        for(auto num: nums){
            int n = finalAns.size();
            for(int i {}; i < n; ++i){
                vector<int> new_vec = finalAns[i];
                new_vec.push_back(num);
                finalAns.push_back(new_vec);
            }
        }
        return finalAns;
    }
};
