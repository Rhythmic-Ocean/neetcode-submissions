class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        int indx {};
        for(int i{}; i < row; ++i){
            for(int j {}; j < col; ++j){
                if(board[i][j] == word[indx]){
                    ++indx;
                    char cur = board[i][j];
                    board[i][j] = '#';
                    if(backtracking(board, word, indx, i, j)) return true;;
                    board[i][j] = cur;
                    --indx;
                }
            }
        }
        return false;
    }

    bool backtracking(vector<vector<char>>& board, string& word, int indx, int r, int c){
        if(indx >= word.size()) return true;
        int row = board.size();
        int col = board[0].size();
        if(r != 0 && board[r-1][c] == word[indx]){
            char cur = board[r-1][c];
            board[r-1][c] = '#';
            if(backtracking(board, word, indx + 1, r-1, c)) return true;;
            board[r-1][c] = cur;
        }
        if(c != 0 && board[r][c-1] == word[indx]){
            char cur = board[r][c -1];
            board[r][c-1] = '#';
            if(backtracking(board, word, indx + 1, r, c-1))return true;
            board[r][c-1] = cur;
        }
        if(r < row - 1 && board[r+1][c] == word[indx]){
            char cur = board[r+1][c];
            board[r+1][c] = '#';
            if(backtracking(board, word, indx + 1, r+1, c)) return true;
            board[r+1][c] = cur;
        }
        if(c < col - 1 && board[r][c+1] == word[indx]){
            char cur = board[r][c +1];
            board[r][c+1] = '#';
            if(backtracking(board, word, indx + 1, r, c+1)) return true;
            board[r][c+1] = cur;
        }
        return false;
    }
};
