class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum {};
        for(int num: nums){
            sum+=num;
        }
        if(std::abs(target) > std::abs(sum)) return 0;
        vector<int> dp(2*sum+1, 0);
        dp[sum] = 1;
        for(int i {n-1}; i >= 0; --i){
            vector<int> local_dp(2*sum+1, 0);
            for(int j {}; j <= 2*sum; ++j){
                if(dp[j] != 0){
                    local_dp[j-nums[i]] += dp[j];
                    local_dp[j+nums[i]] += dp[j];
                } 
            }
            dp = std::move(local_dp);
            local_dp.clear();
        }
        return dp[sum-target];
    }
};
