class FreqStack {
public:
    vector<stack<int>> out ;
    unordered_map<int ,int> mp ; //( num , freq) ;
    int freq = 0 ;
    FreqStack() {
    }

    void push(int val) {
        mp[val]++ ;

        freq = max(freq , mp[val]) ;
        if(mp[val] > out.size()){
            out.push_back(stack<int>()) ;
        }
        out[ mp[val] - 1].push(val) ;
    }

    int pop() {
        int ans = out[freq - 1].top();
        out[freq - 1].pop() ;
        mp[ans]-- ;

        if(out[freq - 1].empty()){
        freq-- ;
        }

        return ans ;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */