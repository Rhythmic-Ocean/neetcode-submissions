class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int cur_sum = nums[0];
        for(int i {1}; i < nums.size(); ++i){
            cur_sum += nums[i];
            //if prev_sum was neg and nums[i]'s +ve
            if(cur_sum < nums[i]){
                cur_sum = nums[i];
            } 
            //both cur sum and nums[i] are positive
            else if(cur_sum > cur_sum - nums[i]){}
            //if nums[i] is negative
            else{
                //update max_sum (update it every time cur_sum bout to decrease)
                //if less than 0, just set the variable up for next stuff on line
                //if greater than 0... then we move on!!
                cur_sum = max(0, cur_sum);
            }
            max_sum = max(cur_sum, max_sum);
        }
        return max(max_sum, cur_sum);
    }
};
