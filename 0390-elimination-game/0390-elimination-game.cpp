class Solution {
public:
    int lastRemaining(int n) {
        int head = 1 ; 
        int step = 1 ; 
        bool left = true ;
        while(n > 1){
            if(left || n % 2 == 1){
                head += step ;
            }
            left = !left ;
            n /= 2 ;
            step *= 2 ;
        }
        return head ;
    }
};