class MyHashSet {
    int map[1000001];
public:
    
    MyHashSet() {
        for(int i=0;i<=1000000;i++){
            this->map[i]=0;
        }
    }
    
    void add(int key) {
        map[key]=+1;
    }
    
    void remove(int key) {
        map[key]=0;
    }
    
    bool contains(int key) {
        return map[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */