class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dps(n+1, vector<int>(amount+1, 0));
        //Because every number has a way to create amount 0
        for(auto& dp: dps){
            dp[0] = 1;
        } 
        for(int i {n-1}; i >= 0;--i){
            for(int j {1}; j <= amount; ++j){
                dps[i][j] = dps[i+1][j];
                if(j - coins[i] >= 0){
                    dps[i][j] += dps[i][j-coins[i]];
                }
            }
        }
        return dps[0][amount];
    }
};
