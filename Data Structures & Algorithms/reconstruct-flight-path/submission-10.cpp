
class Solution {
    int m_total {};
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        deque<string> finalAns {};
        stack<string> recur {};
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
        recur.push(start);
        while(!recur.empty()){
            if(adj_list[recur.top()].empty()){
                 finalAns.push_front(recur.top());
                 recur.pop();
                 continue;
            }
            std::string new_path = adj_list[recur.top()].front();
            adj_list[recur.top()].pop_front();
            recur.push(new_path);
        }
        return {finalAns.begin(), finalAns.end()};
    }

};

