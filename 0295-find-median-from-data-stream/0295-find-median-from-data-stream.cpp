class MedianFinder {
    priority_queue<double,vector<double>,greater<double>> minHeap;
    priority_queue<double,vector<double>> maxHeap;
public:
    MedianFinder() {
        maxHeap = {};
        minHeap = {};
    }
    
    void addNum(int num) {
        if(maxHeap.size()==0){
            maxHeap.push(num);
        }
        else if(maxHeap.top()>num)
        {
            maxHeap.push(num);
            if(maxHeap.size()==minHeap.size()+2)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
        else{
            minHeap.push(num);
            if(minHeap.size()>maxHeap.size()){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }
    
    double findMedian() {
        double ans;
        
        if(minHeap.size()==maxHeap.size()){
            ans = minHeap.top()+maxHeap.top();
            return ans/2;
        }
        else{
            return maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */