class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> finalAns {};
        auto arrS {temperatures.size()};
        finalAns.reserve(arrS);
        for(auto i {0uz}; i < arrS; ++i){
            size_t count {};
            bool temp {false};
            for(auto j {i + 1}; j < arrS; ++j){
                ++count;
                if(temperatures[i] < temperatures[j]){
                    temp = true;
                    break;
                }
            }
            if(!temp)
                count = 0;
            finalAns.push_back(count);
        }
        return finalAns;
    }
};
