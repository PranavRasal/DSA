class Solution {
public:
    int mySqrt(int x) {
        if(x < 2){
            return x ;
        }
        if(x == 2 || x == 3){
            return 1 ;
        }
        long long ans = 2 ;
        long long st = 2 , end = x ; 
        while(st <= end ){
        long long mid = st + (end - st) / 2 ;
        long long sq = mid * mid ;
        if(sq == x){
            return mid ;
        }else if (sq < x){
            st = mid + 1 ;
            ans = mid ;
        }else{
            end = mid - 1 ;
        }
        }
        return ans ;
    }
};