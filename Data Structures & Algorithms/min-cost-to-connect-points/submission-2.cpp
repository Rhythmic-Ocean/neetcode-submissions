
static constexpr int INF =1000000000;
class Solution {
public:
    struct Edge{
    public:
        int w { INF};
        int to {-1};
    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        int total_dist {};
        int n = points.size();
        //calculates weight as per manhattan distance
        auto dist = [&points](int a, int b){
            int x1 = points[a][0];
            int y1 = points[a][1];
            int x2 = points[b][0];
            int y2 = points[b][1];
            return(std::abs(x1-x2) + std::abs(y1-y2));
        };
        //stores minimum edges between any two known points
        vector<Edge> min_e(n);
        min_e[0] = {0, 0};
        //for any functions selected vertices
        vector<bool> selected(n, false);
        for(int i {}; i < n; ++i){
            int v = -1;
            for(int j {}; j < n; ++j){
                if(!selected[j] && (v==-1 || min_e[j].w < min_e[v].w)){
                    v = j;
                }
            }
            selected[v] = true;
            total_dist += min_e[v].w;
            for(int j {}; j < n; ++j){
                if(!selected[j] &&  dist(v, j) < min_e[j].w){
                    min_e[j].w = dist(v, j);
                }
            }
        }
        return total_dist;
    }
};
