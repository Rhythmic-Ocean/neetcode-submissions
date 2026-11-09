class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int finalMax {nums[0]};
        int curMax {nums[0]};
        int curMin {nums[0]};
        for(int i = 1; i < nums.size(); ++i){
            int a = curMax*nums[i];
            int b = curMin*nums[i];
            curMax = max({nums[i],a, b});
            curMin = min({nums[i],a, b});
            finalMax = max(curMax, finalMax);
        }
        return max(finalMax, curMax);
    }
};
