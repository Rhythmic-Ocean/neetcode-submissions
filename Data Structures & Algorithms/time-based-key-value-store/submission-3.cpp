class TimeMap {
       std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> um {}; 
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        um[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!um.count(key)) return "";
        int left {};
        int right = um[key].size() - 1;
        int mid {left + (right - left)/2};
        const auto& myVec {um[key]};
        while(left <= right){
            mid = left + (right - left)/2;
            if(myVec[mid].first == timestamp) return myVec[mid].second;
            else if(myVec[mid].first < timestamp) left = mid + 1;
            else right = mid - 1;
        }

        if(myVec[mid].first > timestamp ){
            if(mid == 0) return "";
            return myVec[mid - 1].second;
        }
        return myVec[mid].second;
    }
};
