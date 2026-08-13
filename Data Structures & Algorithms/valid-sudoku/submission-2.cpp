class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] {false};
        bool col[9][9] {false};
        bool box[9][9] {false};
        for(auto i {0uz}; i < 9; ++i){
            for(auto j {0uz}; j < 9; ++j){
                if(board[i][j] == '.')
                    continue;
                int val {board[i][j] - '1'};
                size_t boxId { (i/3) * 3 + (j/3)};
                if(row[i][val] || col[j][val] || box[boxId][val])
                    return false;
                row[i][val] = true;
                col[j][val] = true;
                box[boxId][val] = true;
            }
        }
        return true;
    }
};
