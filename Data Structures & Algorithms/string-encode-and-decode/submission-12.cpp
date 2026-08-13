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
        size_t i {0uz};
        while(i < s.size()){
            size_t plc {s.substr(i).find_first_of('#')};
            size_t num = {stoul(s.substr(i, plc))};
            vec.push_back(s.substr(i + plc+1, num));
            i += (plc + num + 1);
        }
        return vec;
    }
};
