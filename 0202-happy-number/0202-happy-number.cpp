class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> visi ;
        while(n != 1){
            if(visi.find(n) != visi.end()){
                return false ;
            }
            visi[n]++ ;
            int  sum = 0 ;
            while(n > 0){
                sum = sum + (n%10)*(n%10) ;
                n /= 10 ;
            }
            n = sum ;
            
        }
        return true ;
    }
};