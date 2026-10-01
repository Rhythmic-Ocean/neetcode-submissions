static constexpr int INF=2147483647;
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        deque<pair<int, int>> que {};
        for(int i {}; i < grid.size(); ++i){
            for(int j{}; j < grid[0].size(); ++j){
                if(grid[i][j] == 0){
                    que.push_back({i, j});
                }
            }
        }
        bfs(grid, que);
    }

    void bfs(vector<vector<int>>& grid, deque<pair<int,int>>& que){
        int rw_max = grid.size() - 1;
        int cl_max = grid[0].size() -1;
        int counter {};
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
