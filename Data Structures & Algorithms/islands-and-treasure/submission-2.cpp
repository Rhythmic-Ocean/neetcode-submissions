static constexpr int INF=2147483647;
class Solution {
    static constexpr std::array<pair<int, int>, 4> ARR{{
        {-1, 0}, {0, -1},{1, 0}, {0, 1}
}};
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
            for(auto& arr: ARR){
                auto i = rw+arr.first;
                auto j = cl+arr.second;
                if((i < 0 || i > rw_max) || (j < 0 || j > cl_max)) continue;
                if(grid[i][j] == INF){
                    grid[i][j] = counter;
                    que.push_back({i,j});
                }
            }
        }
    }
};
