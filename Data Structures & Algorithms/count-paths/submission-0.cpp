class Solution {
    static constexpr array<pair<int, int>, 2> ARR{{
        {1, 0}, {0, 1}
    }};
public:
    int uniquePaths(int m, int n) {
       if(m==0 || n == 0) return 0;
       vector<vector<int>> dp(m, vector<int>(n, 0));
       dp[m-1][n-1] = 1;
       for(int i {m-1}; i >= 0; --i){
            for(int j {n-1}; j >= 0; --j){
                for(auto& arr: ARR){
                    int next_i = i+arr.first;
                    int next_j = j+arr.second;
                    if(next_i >= m || next_j >= n) continue;
                    dp[i][j] += dp[next_i][next_j];
                }
            }
       }
       return dp[0][0];
    }
};
