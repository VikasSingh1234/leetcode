class BrowserHistory {
    vector<string> v;
    int curr, last;
public:
    BrowserHistory(string homepage) {
        v.push_back(homepage);
        curr = 0; 
        last = 0;
    }
    
    void visit(string url) {
        curr += 1;
        if (v.size() > curr) {
            v[curr] = url;
        } else {
            v.push_back(url);
        }
        last = curr;
    }
    
    string back(int steps) {
        curr = max(0, curr - steps);
        return v[curr];
    }
    
    string forward(int steps) {
        curr = min(last, curr + steps);
        return v[curr];
    }
};
/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */