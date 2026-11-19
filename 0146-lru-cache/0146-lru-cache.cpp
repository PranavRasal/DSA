class LRUCache {
public:

    class Node {
        public :
        int key , val ;
        Node* prev ;
        Node* next ;
        Node(int ky , int value){
            key = ky ;
            val = value ;
            prev = next = NULL ;
        }
    };
    void addNode(Node* newNode){
        Node* temp = head->next ;
        head->next = newNode ;
        newNode->prev = head ;
        newNode->next = temp ;
        temp->prev = newNode ;
    }

    void delNode(Node* newNode){
        Node* prevNode = newNode->prev ;
        Node* nextNode = newNode->next ;
        prevNode->next = nextNode ;
        nextNode->prev = prevNode ;
    }

    int limit ;
    unordered_map<int , Node*> mp ;
    Node* head = new Node(-1 , -1) ;
    Node* tail = new Node(-1 , -1) ;


    LRUCache(int capacity) {
        limit = capacity ;
        head->next = tail ;
        tail->prev = head ;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1 ;
        }
        Node* temp = mp[key] ;
        delNode(temp) ;
        addNode(temp) ;
        return temp->val ;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* temp =mp[key] ;
            delNode(temp) ;
            mp.erase(key) ;
            delete temp ;
        }
        if(mp.size() == limit){
            Node* temp =tail->prev ;
            delNode(temp) ;
            mp.erase(temp->key) ;
            delete temp ;
        }
        Node* temp = new Node(key , value) ;
        addNode(temp) ;
        mp[key] = temp ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */