class Solution {
    vector<string> finalAns {};
    size_t available {};
    size_t opened {};
public:
    vector<string> generateParenthesis(int n) {
        std::string cur_str {};
        available = n;
        cur_str.push_back('(');
        ++opened;
        --available;
        backtracking(cur_str);
        cur_str.pop_back();
       return finalAns;
    }

    void backtracking(std::string& cur_str){
        if(!available && !opened){
            finalAns.push_back(cur_str);
            return;
        }
        if(opened){
            cur_str.push_back(')');
            --opened;
            backtracking(cur_str);
            ++opened;
            cur_str.pop_back();
        }
        if(available){
            cur_str.push_back('(');
            --available;
            ++opened;
            backtracking(cur_str);
            ++available;
            --opened;
            cur_str.pop_back();
        }
        return;
    }
};
