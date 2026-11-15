class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> maxBuy (n+2, 0);
        for(int i {n-1}; i >= 0; --i){
            int local_profit = {};
            for(int j = i; j < n; ++j){
                int profit {};
                if(prices[i] >= prices[j]){
                    profit = maxBuy[j+1];
                }else{
                    profit = max(prices[j] - prices[i] + maxBuy[j+2], maxBuy[j+1]);
                }
                local_profit = max(profit, local_profit);
            }
            maxBuy[i] = local_profit;
        }
        return maxBuy[0];
    }
};
