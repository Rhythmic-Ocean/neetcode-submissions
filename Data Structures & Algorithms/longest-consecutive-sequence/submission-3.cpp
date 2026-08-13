class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::priority_queue<int> myQ (nums.begin(), nums.end());
        if(myQ.empty())
            return 0;
        int max_count {1};
        int cur_count {1};
        int last_el {myQ.top()};
        myQ.pop();
        while(!myQ.empty()){
            if(myQ.top() == (last_el - 1))
                ++cur_count;
            else if(myQ.top() == last_el){}
            else
                cur_count = 1;
            last_el = myQ.top();
            myQ.pop();
            if(cur_count > max_count)
                max_count = cur_count;
        }
        return max_count;
    }
};
