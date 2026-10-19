//Optimized Dijkstra DOES NOT WORK HERE, use priority queue instead of BST!!
//Have to preserve the weights of previous edges as well in case the current mininum edge happens to be a bust

namespace std{
    template<>
    struct hash<pair<int, int>>{
        size_t operator()(const pair<int, int>& p) const{
            return std::hash<int>{}(p.first)^std::hash<int>{}(p.second);
        }
    };
}
#include <print>
class Solution {
    static constexpr int INF = 100000;
    struct Edge{
        int to = -1;
        int w = INF;
        int n = INF;
    };


public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<Edge>> adj_list(n);
        for(auto& flight: flights){
            adj_list[flight[0]].emplace_back(Edge{flight[1], flight[2]});
        }
        auto cmp = [](const Edge& e1, const Edge& e2){
            return e1.w > e2.w;
        };

        priority_queue<Edge, vector<Edge>, decltype(cmp)>q {};
        q.push({src, 0, -1});
        unordered_set<pair<int, int>> known;
        int min_weight = INF;

        while(!q.empty()){
            const auto &edge = q.top();
            int vertex = edge.to;
            int weight = edge.w;
            int num = edge.n;
            q.pop();
            if(vertex == dst ){
                return weight;
            }
            if(k < num+1) continue;
            std::print("vertex = {}\n weight = {}\n num = {}\n\n", vertex, weight, num);
            known.insert({vertex, num});
            std::cout << "{";
            std::string comm = "";
            for(auto& c_edge: adj_list[vertex]){
                int c_vertex = c_edge.to;
                int c_weight = c_edge.w;
                int c_num = c_edge.n;
                std::cout << comm << c_vertex  << "->"  << weight + c_weight;
                comm = ",";
                if(!known.contains({c_vertex, num+1})){
                    q.push(Edge{c_vertex, weight+c_weight, num + 1});
                }else{
                    std::cout << " "  <<c_vertex << " is known!";
                }
            }
            std::cout << ")\n";
        }
        return -1;
    }
};