static constexpr int INF=2147483647;
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int i {}; i < grid.size(); ++i){
            for(int j{}; j < grid[0].size(); ++j){
                if(grid[i][j] == 0){
                    bfs(grid, i, j);
                }
            }
        }
    }

    void bfs(vector<vector<int>>& grid, int row, int col){
        int rw_max = grid.size() - 1;
        int cl_max = grid[0].size() -1;
        int counter {};
        deque<pair<int, int>> que {};
        que.push_back({row, col});
        while(!que.empty()){
            auto[rw, cl] = que.front();
            counter = grid[rw][cl] + 1;
            que.pop_front();
            if(rw != 0 && grid[rw-1][cl] != -1){
                if(grid[rw-1][cl] > counter){
                    grid[rw-1][cl] = counter;
                    que.push_back({rw-1,cl});
                }
            }
            if(cl != 0 && grid[rw][cl-1] != -1){
                if(grid[rw][cl-1] > counter){
                    grid[rw][cl - 1] = counter;
                    que.push_back({rw,cl-1});
                }
            }
            if(rw != rw_max && grid[rw+1][cl] != -1){
                if(grid[rw+1][cl] > counter){
                    grid[rw+1][cl] = counter;
                    que.push_back({rw+1,cl});
                }
            }
            if(cl != cl_max && grid[rw][cl+1] != -1){
                if(grid[rw][cl+1] > counter){
                    grid[rw][cl + 1] = counter;
                    que.push_back({rw,cl+1});
                }
            }
        }
    }
};
