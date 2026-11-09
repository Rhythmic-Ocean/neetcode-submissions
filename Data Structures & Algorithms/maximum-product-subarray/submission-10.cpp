class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        int finalMax {nums[0]};
        int curMax {nums[0]};
        int curMin {nums[0]};
        for(int i = 1; i < nums.size(); ++i){
            if(curMin == 0){
                curMax = nums[i];
                curMin = nums[i];
            }else if(curMin > 0){
                curMax *= nums[i];
                curMin *= nums[i];
            }else{
                if(nums[i] < 0){
                    std::swap(curMax, curMin);
                    curMax *= nums[i];
                    if(curMin > 0){
                        curMin *= nums[i];
                    }else{
                        curMin = nums[i];
                    }
                }else{
                    if(curMax > 0)
                        curMax *= nums[i];
                    else
                        curMax = nums[i];
                    curMin *= nums[i];
                }
            }
            finalMax = max(curMax, finalMax);
        }
        return max(finalMax, curMax);
    }
};
