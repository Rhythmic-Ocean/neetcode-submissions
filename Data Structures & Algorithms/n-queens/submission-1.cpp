class Solution {
    struct Status{
        std::vector<bool> col;
        std::vector<bool> diag1;
        std::vector<bool> diag2;
        Status(int c, int d1, int d2): col(c, false), diag1(d1, false), diag2(d2, false){}

        void mark(int cl, int rw){
            col[rw] = true;
            diag1[rw+cl] = true;
            diag2[rw-cl+col.size()+1]= true;
        }

        void unmark(int cl, int rw){
            col[rw] = false;
            diag1[rw+cl] = false;
            diag2[rw-cl+col.size()+1]= false;
        }

        bool check(int cl, int rw){
            if(col[rw]) return false;
            if(diag1[rw+cl]) return false;
            if(diag2[rw-cl+col.size()+1]) return false;
            return true;
        }
    };
public:
    vector<vector<string>> solveNQueens(int n) {
        if(n == 0) return {};
       std::vector<std::vector<string>> finalAns {};
       std::string str (n, '.'); 
       std::vector cur_board(n, str);
       Status stats {n, 2*n - 1, 2*n - 1};
       int indx {};
       for(int i {}; i < n; ++i){
         cur_board[indx][i] = 'Q'; 
         stats.mark(indx,i);
         backtrack(finalAns, cur_board, n, indx+1, stats);
         stats.unmark(indx, i);
         cur_board[indx][i] = '.';
       }
       return finalAns;
    }

    void backtrack(vector<vector<string>>& finalAns, vector<string>& cur_board, int n, int indx, Status& stats){
        if(indx == n){
            finalAns.push_back(cur_board);
            return;
        }
        for(int i {}; i < n; ++i){
            cur_board[indx][i] = 'Q';
            if(stats.check(indx,i)){
                stats.mark(indx,i);
                backtrack(finalAns, cur_board, n, indx+1, stats);
                stats.unmark(indx,i);
            }
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
