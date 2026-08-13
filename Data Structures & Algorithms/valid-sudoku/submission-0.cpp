class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_set<char> mySet {};
        std::vector<std::pair<int, std::unordered_set<char>>> sqMapping(board.size());
        for(auto i {0uz}; i < board.size(); ++i){
            mySet.clear();
            auto count {0uz};
            for(auto j {0uz}; j < board.size(); ++j){
                size_t currSq {(i/3)*3 + (j/3)};
                if(board[i][j] == '.')
                    continue;
                mySet.insert(board[i][j]);
                sqMapping[currSq].second.insert(board[i][j]);
                ++sqMapping[currSq].first;
                ++count;
            }
            if(count != mySet.size())
                return false;
            mySet.clear();
            count = 0uz;
            for(auto j {0uz}; j < board.size(); ++j){
                if(board[j][i] == '.')
                    continue;
                mySet.insert(board[j][i]);
                ++count;
            }
            if(count != mySet.size())
                return false;
        }
        for(const auto& item: sqMapping){
            if(item.first != item.second.size())
                return false;
        } 
        return true;
    }
};
