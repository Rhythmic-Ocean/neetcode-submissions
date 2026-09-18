class MedianFinder {
    size_t n {};
    priority_queue<int, vector<int>, greater<int>> minHeap_upperHalf {};
    priority_queue<int> maxHeap_lowerHalf {};
    int odd_med {};
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(n == 0){
            odd_med = num;
        }
        else if(n % 2 != 0) //new element will make it even
        {
            int mn = min(odd_med, num);
            int mx = max(odd_med, num);
            if(n != 1 && mn >= minHeap_upperHalf.top()){ //both odd_med and num nw go to upper Half
                maxHeap_lowerHalf.push(minHeap_upperHalf.top());
                minHeap_upperHalf.pop();
                minHeap_upperHalf.push(num);
                minHeap_upperHalf.push(odd_med);
            }
            else if(n != 1 && mx <= maxHeap_lowerHalf.top()){//both odd_med and num should go to lower half
                minHeap_upperHalf.push(maxHeap_lowerHalf.top());
                maxHeap_lowerHalf.pop();
                maxHeap_lowerHalf.push(num);
                maxHeap_lowerHalf.push(odd_med);
            }
            else{
                maxHeap_lowerHalf.push(mn);
                minHeap_upperHalf.push(mx);
            }
        }
        else{ //new element will make it odd
            if(num > minHeap_upperHalf.top()){
                odd_med = minHeap_upperHalf.top();
                minHeap_upperHalf.pop();
                minHeap_upperHalf.push(num);
            }else if(num < maxHeap_lowerHalf.top()){
                odd_med = maxHeap_lowerHalf.top();
                maxHeap_lowerHalf.pop();
                maxHeap_lowerHalf.push(num);
            }else
                odd_med = num;
        }
        n++;
    }
    
    double findMedian() {
        if(n % 2 == 0)
            return (minHeap_upperHalf.top() + maxHeap_lowerHalf.top())/2.0; 
        return odd_med;
    }
};
