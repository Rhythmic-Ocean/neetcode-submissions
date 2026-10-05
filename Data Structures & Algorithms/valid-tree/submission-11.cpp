class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.empty()) return true;
        vector<vector<int>> adj_list (n);
        vector<int> parent (n, -1);
        for(auto& edge: edges){
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        deque<int> q {};
        q.push_back(0);
        int counter {}; //each vertex should only appear twice
        while(!q.empty() && counter < n){
            int vertex = q.front();
            counter++;
            std::cout << vertex  <<", " << counter << std::endl;
            q.pop_front();
            if(adj_list[vertex].empty()) continue;
            for(int w: adj_list[vertex]){
                if(parent[vertex] != -1){
                    if(parent[vertex] == w) continue;
                }
                q.push_back(w);
                std::cout << ">>" << w << std::endl;
                parent[w] = vertex;
            }
        }
        if(!q.empty()) {
            std::cout << "q" << q.size() << std::endl;
            return false;
        }
        if(counter != n) return false;
        return true;
    }
};
