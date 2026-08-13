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
            size_t plc {s.find('#', i)};
            size_t num = {stoul(s.substr(i, plc - i))};
            vec.push_back(s.substr(plc+1, num));
            i = (plc + num + 1);
        }
        return vec;
    }
};
