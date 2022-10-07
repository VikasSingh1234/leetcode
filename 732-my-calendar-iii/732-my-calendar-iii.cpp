class MyCalendarThree {
public:
    map<int, int> cal;
    int maximum;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        cal[start]++;
        cal[end]--;
        int count=0;
        for(auto it:cal){
            count += it.second; 
            maximum = max(maximum,count);
        }
        
        return maximum;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */