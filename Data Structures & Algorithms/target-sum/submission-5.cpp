class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum {};
        for(int num: nums){
            sum+=num;
        }
        if(target > 0 && target > sum || target < 0 && target < -sum) return 0;
        vector<vector<int>> dp(n+1, vector<int>(2*sum+1, 0));
        dp[n][sum] = 1; 
        for(int i {n}; i > 0; --i){
            for(int j {}; j <= 2*sum; ++j){
                if(dp[i][j] != 0){
                    int next = nums[i-1];
                    dp[i-1][j-next]+=dp[i][j];
                    dp[i-1][j+next]+=dp[i][j];
                }
            }
        }
        return dp[0][sum-target];
    }
};
