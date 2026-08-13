class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> dup;
        for(const int & num: nums){
            dup.insert(num);
        }
        if(dup.size() < nums.size())
            return true;
        return false;
    }
};