class KthLargest {
public:
int m_k {};
std::priority_queue<int, vector<int>, greater<int>> q {};
    KthLargest(int k, vector<int>& nums): m_k{k} {
        for(auto num: nums) add(num);
    }
    
    int add(int val) {
       q.push(val);
       if(q.size() > m_k) q.pop();
       return q.top(); 
    }
};
