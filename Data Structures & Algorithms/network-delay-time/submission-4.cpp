class Solution {
    struct Vertex{
        bool known = false;
        int dist = 1000000000;
        vector<vector<int>> edges{};
    };
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<Vertex> adj_list(n+1);
       for(auto& time: times){
        adj_list[time[0]].edges.push_back({time[1], time[2]});
       } 
       auto min_dist = [adj_list](int a, int b){
        return adj_list[a].dist > adj_list[b].dist;
       };
       priority_queue<int, std::vector<int>, decltype(min_dist)> q(min_dist);
       adj_list[k].dist = 0;
       q.push(k);
       while(!q.empty()){
        Vertex v = adj_list[q.top()];
        q.pop();
        v.known = true;
        std::cout << std::endl;
        for(auto& edge: v.edges){
            Vertex &w = adj_list[edge[0]];
            if(!w.known){
                std::cout << ">>" << edge[0]<< std::endl; 
                if(w.dist > edge[1] + v.dist){
                    w.dist = edge[1] + v.dist;
                    q.push(edge[0]);
                }
            }
        }
       }
       int max {};
       for(int i = 1; i < n+1; ++i){
        if(adj_list[i].dist == 1000000000) return -1;
        if(adj_list[i].dist > max) max = adj_list[i].dist;
       }
       return max;

    }
};
