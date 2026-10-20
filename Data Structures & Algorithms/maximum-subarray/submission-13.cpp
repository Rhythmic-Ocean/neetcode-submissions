class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int cur_sum = nums[0];
        for(int i {1}; i < nums.size(); ++i){
            //if prev_sum was neg and nums[i]'s +ve
            if(cur_sum > 0){
                cur_sum+=nums[i];
                max_sum = max(max_sum, cur_sum);
            }else{
                cur_sum = nums[i];
            }
        }
        return max(max_sum, cur_sum);
    }
};
