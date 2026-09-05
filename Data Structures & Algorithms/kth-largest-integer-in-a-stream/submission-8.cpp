class KthLargest {
    int m_count{};
    int m_cap {};
    std::priority_queue<int, vector<int>, greater<int>> q {};
public:
    KthLargest(int k, vector<int>& nums): m_cap {k} {
        int i {};
        for(; i < nums.size(); ++i){
            q.push(nums[i]);
            ++m_count;
            if(m_count >= m_cap) break;
        }
        ++i;
        if(i < nums.size()){
            for(; i < nums.size(); ++i){
                int a = add(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(!q.empty() && val < q.top()) return q.top();
        if(m_count < m_cap){
            ++m_count;
            q.push(val);
            return q.top();
        }
        q.pop();
        q.push(val);
        return q.top();
    }
};
