class SmallestInfiniteSet {
    unordered_set<int> s;
    priority_queue<int, vector<int>, greater<int>> pq;
    int minimum;

public:
    SmallestInfiniteSet() {
        minimum = 1;
    }

    int popSmallest() {
        int answer;
        if (!pq.empty()) {
            answer = pq.top();
            s.erase(answer);
            pq.pop();
        } 
        else {
            answer = minimum;
            minimum += 1;
        }
        return answer;
    }

    void addBack(int num) {
        if (minimum <= num || 
            s.find(num) != s.end()) {
            return;
        }
        pq.push(num);
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */