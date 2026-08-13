class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        bool ana {false};
        vector<vector<string>> finalAns{};
        for(const auto& str: strs){
            ana = false;
            for(auto i {0uz}; i < finalAns.size(); ++i){
                vector<int> alph(26);
                ana = true;
                if(finalAns[i][0].size() != str.size()){
                    ana = false;
                    continue;
                }
                for(auto cha: finalAns[i][0]){
                    alph[cha - 'a'] += 1;
                }
                for(auto cha: str){
                    alph[cha - 'a'] -= 1;
                }
                for(auto ch: alph){
                    if(ch != 0){
                        ana = false;
                        break;
                    }
                }
                if(ana){
                    finalAns[i].emplace_back(str);
                    break;
                }
            }
            if(!ana)
                finalAns.emplace_back(std::vector<string>{std::move(str)}); 
        }
        return finalAns;
    }
};