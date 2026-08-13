class Solution {
public:
    int maxProfit(vector<int>& h) {
        int n = h.size();
        if(n <= 1)
            return 0;
        int p1 {};
        int p2  {p1 + 1};
        int sell {p2};
        int max_prof {};
        int cur_prof {};
        while(p2 < n){
           if( h[p2] <=  h[p1]){
               p1 = p2;
           }
           cur_prof = h[p2] - h[p1];
           max_prof = max(max_prof, cur_prof);
           ++p2;
        }
        return max_prof;
    }
};
