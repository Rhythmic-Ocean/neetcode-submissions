class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_set<char> mySet {};
        std::vector<std::unordered_set<char>> sqMapping(board.size());
        for(auto i {0uz}; i < board.size(); ++i){
            mySet.clear();
            for(auto j {0uz}; j < board.size(); ++j){
                size_t currSq {(i/3)*3 + (j/3)};
                if(board[i][j] == '.')
                    continue;
                if(mySet.contains(board[i][j]) || sqMapping[currSq].contains(board[i][j]))
                    return false;
                mySet.insert(board[i][j]);
                sqMapping[currSq].insert(board[i][j]);
            }
            mySet.clear();
            for(auto j {0uz}; j < board.size(); ++j){
                if(board[j][i] == '.')
                    continue;
                if(mySet.contains(board[j][i]))
                    return false;
                mySet.insert(board[j][i]);
            }
        }
        return true;
    }
};
