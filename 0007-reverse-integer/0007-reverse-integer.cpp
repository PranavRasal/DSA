class Solution {
public:
    int reverse(int x) {
       int sign = 1 ;
       long long num = x ;
       if(x < 0){
        sign = -1 ;
        num *= -1 ;
       } 
       long long ans = 0 ; 
       while(num > 0){
        ans *= 10 ;
        int div = num % 10 ;
        ans += div ;
        num /= 10 ;
        if(ans > INT_MAX || ans < INT_MIN){
        return 0 ;
        }
       }
       
       return sign * ans ;
    }
};