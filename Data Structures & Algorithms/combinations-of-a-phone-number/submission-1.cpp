class Solution {
    std::vector<string> finalAns {};
    static constexpr std::array<string, 8> keypad {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        std::string new_char {};
        new_char.reserve(digits.size());
        for(auto ch: keypad[digits[0] - '2']){
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
        for(auto ch: keypad[digits[indx]- '2']){
            new_char.push_back(ch);
            backtracking(digits, new_char, indx + 1);
            new_char.pop_back();
        }
    }

};
