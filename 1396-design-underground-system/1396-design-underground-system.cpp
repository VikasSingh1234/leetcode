class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> In;
    unordered_map<string,pair<double,int>> p;
    int trips = 0;
    UndergroundSystem() {
        this->In = {};
        this->p = {};
    }
    
    void checkIn(int id, string stationName, int t) {
        this->In[id]={stationName,t};
        return ;
    }
    
    void checkOut(int id, string stationName, int t) {
        string route = In[id].first+"-"+stationName;
        if(p.find(route)==p.end()){
            p[route] = {0,0};
        }
        p[route].first+=(t-In[id].second);
        p[route].second += 1;
        In.erase(id);
        trips++;
        return ;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation+"-"+endStation;
        return p[route].first/p[route].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */