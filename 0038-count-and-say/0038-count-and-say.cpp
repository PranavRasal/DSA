class Solution {
public:
    string helper(int n){
        if(n == 1){
            return to_string(1) ;
        }
        string num = helper(n - 1) ;
        string ans = "" ;
       
        for(int i = 0 ; i < num.size() ; i++){
            char ch = num[i] ;
            int count = 1 ;
            while(i < num.size() - 1 && num[i] == num[i+1]){
                i++ ;
                count++ ;
            }
            ans += to_string(count) + ch ;
        }
        return ans ;
    }
    string countAndSay(int n) {
        string ans = helper(n) ;
        return ans ;
    }
};