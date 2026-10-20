class Solution {
public:
    bool canJump(vector<int>& nums) {
    int i {};
    while(i < nums.size() - 1){
        std::cout << i << std::endl;
        if(nums[i] == 0) return false;
        int max_jmp {};
        int max_sum_jmp {};
        int cur_place {};
        //total sum of the highest jumping capacity
        for(int j {1}; j <= nums[i]; ++j){
            cur_place = i+j;
            if(cur_place >= nums.size() - 1) return true;
            if(nums[i+j] == 0) continue;
            if(max_sum_jmp < j+nums[i+j]){
                max_sum_jmp = j+nums[i+j];
                max_jmp = j;
            }
        }
        if(max_jmp == 0) return false;
        i+= max_jmp;
       } 
       return true;
    }
};
