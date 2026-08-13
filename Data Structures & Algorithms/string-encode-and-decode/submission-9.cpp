class Solution {
public:

    string encode(vector<string>& strs) {
        std::string myStr {};
        for(const auto& str: strs){
            myStr+=std::format("{}#{}", str.size(), str);
        }
        return myStr;
    }

    vector<string> decode(string s) {
        std::vector<string> vec {};
        while(!s.empty()){
            size_t plc {s.find_first_of('#')};
            size_t num = {stoul(s.substr(0, plc))};
            vec.push_back(s.substr(plc+1, num));
            s.erase(0, num + plc + 1);
        }
        return vec;
    }
};
