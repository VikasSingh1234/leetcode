class TimeMap {
public:
    unordered_map<string,unordered_map<int,string>> time;
    TimeMap() {
       time = {};
    }
    
    void set(string key, string value, int timestamp) {
        time[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        
        if(time.find(key)!=time.end()){
            for(int i=timestamp;i>=1;i--){
                if(time[key].find(i)!=time[key].end()){
                    return time[key][i];
                }
            }
        }
        
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */