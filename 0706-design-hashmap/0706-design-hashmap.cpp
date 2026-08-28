class MyHashMap {
public:
    vector<int> V;
    MyHashMap() {
        V.resize(1000001 , -1);
    }
    
    void put(int key, int value) {
        V[key] = value ;
    }
    
    int get(int key) {
        if(V[key] == -1){
            return -1 ;
        }
        return V[key] ;
    }
    
    void remove(int key) {
        V[key] = -1 ;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */