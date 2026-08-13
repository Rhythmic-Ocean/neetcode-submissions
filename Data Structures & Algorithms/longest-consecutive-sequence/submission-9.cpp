class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       std::unordered_set<int> mySet (nums.begin(), nums.end()); 
       int count {};
       int max_count {};
       for(const auto num: nums){
        if(mySet.contains(num - 1))
            continue;
        int cur_el {num};
        count = 1;
        while(mySet.contains(cur_el + 1)){
            count++;
            cur_el++;
        }
        if(count > max_count)
            max_count = count;
       }
       return max_count;
    }
};
