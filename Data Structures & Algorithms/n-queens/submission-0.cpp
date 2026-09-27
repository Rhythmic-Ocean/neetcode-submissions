class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if(n == 0) return {};
       std::vector<std::vector<string>> finalAns {};
       std::string str (n, '.'); 
       std::vector cur_board(n, str);
       int indx {};
       for(int i {}; i < n; ++i){
         cur_board[indx][i] = 'Q'; 
         backtrack(finalAns, cur_board, n, indx+1);
         cur_board[indx][i] = '.';
       }
       return finalAns;
    }

    void backtrack(vector<vector<string>>& finalAns, vector<string>& cur_board, int n, int indx){
        if(indx == n){
            finalAns.push_back(cur_board);
            return;
        }
        for(int i {}; i < n; ++i){
            cur_board[indx][i] = 'Q';
            if(check(cur_board, i, indx))
                backtrack(finalAns, cur_board, n, indx+1);
            cur_board[indx][i] = '.';
        }
    }

    bool check(const vector<string>& cur_board, int pos, int indx){
        int n {};
        //we check in prev rows
        for(int i = indx - 1; i >= 0; --i){
            if(cur_board[i][pos] == 'Q') return false;
        }
        //checking diagonally down
        for(int i = indx - 1, m = pos - 1; i >=0 && m >=0; --i, --m){
            if(cur_board[i][m] == 'Q') return false;
        }
        //checking diagonally up
        for(int i = indx - 1, n = pos + 1; i >=0 && n < cur_board.size();--i, ++n){
            if(cur_board[i][n] == 'Q') return false;
        }
        return true;
    }
};
