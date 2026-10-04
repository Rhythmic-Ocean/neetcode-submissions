class Solution {
    struct Point{
       int x;
       int y;
    };

static constexpr std::array<Point, 4> ARR{{
    {-1, 0}, {0, -1}, {1, 0}, {0, 1}
}};
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        deque<Point> q {};
        for(int i {}; i < board.size(); ++i){
            for(int j {}; j < board[0].size(); ++j){
                if(i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size() - 1){
                    if(board[i][j] == 'O'){
                        dfs(board, {i, j});
                    }
                }
            }
        }
        for(int i {}; i < board.size(); ++i){
            for(int j {}; j < board[0].size(); ++j){
                if(board[i][j] == 'K') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
        return;
    }

    void dfs(vector<vector<char>> & board, Point point){
        board[point.x][point.y] = 'K';
        for(auto& arr: ARR){
            auto[i, j] = arr;
            i += point.x;
            j += point.y;
            if(i < 0 || j < 0 || i >=board.size() || j >= board[0].size()) continue;
            if(board[i][j] == 'O')
                dfs(board, {i, j});
        }
    }
};
