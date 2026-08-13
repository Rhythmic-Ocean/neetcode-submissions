class VectorInt
{
    public:
    size_t operator() (const std::vector<int> & vecInt) const
    {
        size_t returnVal {};
        static hash<int> intHash;
        for(const auto num: vecInt){
            returnVal += intHash(num);
        }
        return returnVal;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::vector<int>, std::vector<string>, VectorInt> mymap {};
        for(const auto& str: strs){
            std::vector<int> gloVec(26);
            for(auto ch: str){
                gloVec[ch - 'a'] += 1;
            }
            mymap[gloVec].push_back(str);
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