class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> dup;
        for(const int & num: nums){
            if(dup.insert(num).second == false)
                return true;
        }
        return false;
    }
};