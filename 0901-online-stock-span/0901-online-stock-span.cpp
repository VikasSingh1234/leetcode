class StockSpanner {
    vector<int> line;
public:
    StockSpanner() {
        line = {};
    }
    
    int next(int price) {
        line.push_back(price);
        int ans = 0;
        int n = line.size();
        for(int i=n-1;i>=0;i--){
            if(line[i]<=price){
                ans+=1;
            }
            else{
                break;
            }
        }
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */