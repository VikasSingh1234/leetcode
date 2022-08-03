class MyCalendar {
public:
    vector<pair<int,int>> vect;
    MyCalendar() {
        vect.push_back(make_pair(0,0));
    }
    
    bool book(int start, int end) {
        
        
        for(int i=1;i<vect.size();i++){
            if(end>vect[i].first && start<vect[i].second){
                return false;
            }
            
        }
        
        vect.push_back(make_pair(start,end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */