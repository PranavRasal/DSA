class MedianFinder {
public:
    priority_queue<int> left ;
    priority_queue<int , vector<int> , greater<int>> right;
    MedianFinder() {}
    
    void addNum(int num) {
        if(left.empty() || num <= left.top()){
            left.push(num);
        }else{
            right.push(num);
        }
        if(left.size() < right.size() ){
                left.push(right.top()) ;
                right.pop();
            }
        if(left.size() > right.size() + 1){
            right.push(left.top());
            left.pop();
        }}

    double findMedian() {
        if((right.size() + left.size()) % 2 == 0 ){
           return   (right.top() + left.top()) / 2.0 ;
        }else{
            if(!left.empty()){
            return left.top();
            }}
            return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */