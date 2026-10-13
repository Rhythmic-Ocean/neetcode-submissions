
class Solution {
    int m_total {};
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        deque<string> finalAns {};
        int total_destination {1}; //1 cuz they start from JFK
        vector<vector<string>> visited {};
        std::sort(tickets.begin(), tickets.end(), [](vector<string>& a, vector<string>& b){
            return a[1] < b[1];
        });
        if(tickets.empty()) return {};
        unordered_map<string, deque<string>> adj_list {};
        //creating adj_list
        for(auto& ticket: tickets){
            ++total_destination;
            adj_list[ticket[0]].push_back(ticket[1]);
        }
        m_total = total_destination;
        //start from JFK for dfs
        std::string start = "JFK";
        dfs(adj_list,  finalAns, start);
        finalAns.push_front(start);
        return {finalAns.begin(), finalAns.end()};
    }

    void dfs(unordered_map<string, deque<string>>& adj_list, deque<string>& finalAns, std::string& path){
        if(!adj_list.contains(path) || adj_list[path].empty()){
            return;
        }
        int path_no = adj_list[path].size();
        while(!adj_list[path].empty()){
            std::string new_path = std::move(adj_list[path].front());
            adj_list[path].pop_front();
            dfs(adj_list, finalAns, new_path);
            finalAns.push_front(new_path);
        }
    }
};

