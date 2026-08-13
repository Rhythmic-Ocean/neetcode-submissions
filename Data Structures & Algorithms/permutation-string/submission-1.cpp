class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char,  int> myMap {};
        std::unordered_map<char, int> myMap2{};
        int n1 = s1.size();
        int n2 = s2.size();
        for(const auto ch: s1){
            myMap[ch]++;
        }
        int p1 {};
        int p2 {};
        while (p1 < n2){
            p2 = p1;
            while(myMap.find(s2[p1])== myMap.end() && p1 < n2){
                ++p1;++p2;
            }
            if(p1 >= n2)
                break;
            while(p2 < n2){
                if(myMap.find(s2[p2]) != myMap.end() && myMap[s2[p2]] != 0){
                    if(myMap2.find(s2[p2]) == myMap2.end()){
                        myMap2[s2[p2]] = myMap[s2[p2]];
                    }
                    myMap[s2[p2]]--;
                    ++p2;
                }
                else
                    break;
            }
            if(p2 - p1 == n1)
                return true;
            ++p1;
            for(auto items: myMap2){
                myMap[items.first] = items.second;
            }
            myMap2.clear();
        }
        return false;
    }
};