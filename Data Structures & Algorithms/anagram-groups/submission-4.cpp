class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<string>> mymap {};
        for(const auto& str: strs){
            std::string key(26, 0);
            for(auto ch: str){

                key[ch - 'a']++;
            }
            mymap[key].push_back(str);
        }
        std::vector<std::vector<string>> finalAns(mymap.size());
        size_t i {};
        for(const auto& item: mymap){
            finalAns[i] = std::move(item.second);
            i++;
        }
        return finalAns;
    }
};