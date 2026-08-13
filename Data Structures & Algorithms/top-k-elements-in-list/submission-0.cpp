struct Comparator{
    bool operator()(const std::pair<int, int>& map1, const std::pair<int, int>& map2) const{
        return map1.second < map2.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Comparator> myQ;
        std::unordered_map<int, int> myMap{};
        std::vector<int> finalAns;
        for(const auto num : nums){
            myMap[num]++;
        }
        for(const auto& item: myMap){
            myQ.push(item);
        }
        for(auto i {0uz}; i < k; ++i){
            finalAns.push_back(myQ.top().first);
            myQ.pop();
        }
        return finalAns;
    }
};
