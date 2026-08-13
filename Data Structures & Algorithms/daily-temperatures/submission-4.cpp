class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n  = temperatures.size();
        std::vector<int> finalAns (n, 0);
        for(auto i{n - 2}; i >= 0; --i){
            auto curr {i  + 1};
            while(curr < n && temperatures[curr] <= temperatures[i]){
                if(finalAns[curr] == 0){
                    curr = n;
                    break;
                }
                curr += finalAns[curr];
            }
            if(curr < n){
                finalAns[i] = curr - i;
            }
        }
        return finalAns;
    }
};
