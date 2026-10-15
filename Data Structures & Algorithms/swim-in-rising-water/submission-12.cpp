static constexpr int INF = 1000000000;
class Solution {
    struct Edge{
        int w {INF};
        int to = -1;
        bool operator<(const Edge& other) const{
            return make_pair(w, to) < make_pair(other.w, other.to);
        }
    };
    static constexpr std::array<pair<int, int>, 4> dirn{{
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    }};
public:
    int swimInWater(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int row_size = grid.size();
        int col_size = grid[0].size();
        int total_size = grid.size() * grid[0].size();
        set<Edge> q {}; 
        vector<Edge> min_e(total_size);
        min_e[0].w = grid[0][0];
        vector<bool> selected(total_size, false);
        q.insert({grid[0][0], 0});
        while(!q.empty()){
            int cell = q.begin()->to;
            int cu_w = q.begin()->w;
            int rw = cell/col_size;
            int cl = cell%col_size;
            selected[cell] = true;
            q.erase(q.begin());
            for(auto& a: dirn){
                int x = rw + a.first;
                int y = cl + a.second;
                if(x < 0 || y < 0 || x > grid.size() - 1 || y > grid[0].size() - 1) continue;
                int c = x*col_size + y;
                if(!selected[c] && min_e[c].w > max(grid[x][y], cu_w)){
                    q.erase({min_e[c].w, c});
                    min_e[c].w = max(grid[x][y], cu_w);
                    q.insert({min_e[c].w, c});
                }
            }
        }
        return min_e[total_size - 1].w;
    }
};
