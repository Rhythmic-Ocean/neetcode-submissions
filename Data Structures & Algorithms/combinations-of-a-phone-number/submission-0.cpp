class Solution {
    std::vector<string> finalAns {};
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        std::string new_char {};
        new_char.reserve(digits.size());
        std::string chars = get_char(digits[0] - '0');
        for(auto ch: chars){
            new_char.push_back(ch);
            backtracking(digits, new_char, 1);
            new_char.pop_back();
        }
        return finalAns;

    }

    void backtracking(string& digits, string& new_char, int indx){
        if(digits.size() == indx){
            finalAns.push_back(new_char);
            return;
        }
        std::string chars = get_char(digits[indx] - '0');
        for(auto ch: chars){
            new_char.push_back(ch);
            backtracking(digits, new_char, indx + 1);
            new_char.pop_back();
        }
    }

    std::string get_char(int num){
        std::string alph {};
        if(num < 7){
            for(int i {}; i < 3; ++i)
                alph += (((num - 2)*3) + i + 'a');
            return alph;
        }
        if(num == 7){
            for(int i {}; i < 4; ++i)
                alph += (((num - 2)*3) + i + 'a');
            return alph;
        }
        if(num == 8){
            for(int i {}; i < 3; ++i)
                alph += ((19) + i + 'a');
            return alph;
        }
        if(num == 9){
            for(int i {}; i < 4; ++i)
                alph += ((22) + i + 'a');
            return alph;
        }
    }
};
