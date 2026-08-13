class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        uint16_t row[9] {0b00000000};
        uint16_t col[9] {0b00000000};
        uint16_t box[9] {0b00000000};
        for(auto i {0uz}; i < 9; ++i){
            for(auto j {0uz}; j < 9; ++j){
                if(board[i][j] == '.')
                    continue;
                int val {board[i][j] - '1'};
                uint16_t mask {static_cast<uint16_t>(1 << val)};
                size_t boxId { (i/3) * 3 + (j/3)};
                if(row[i] & mask || col[j] & mask || box[boxId] & mask)
                    return false;
                row[i] |= mask;
                col[j] |= mask;
                box[boxId] |= mask;
            }
        }
        return true;
    }
};
