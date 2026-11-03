class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0 ; 
        int close = 0 ;
        int result = 0 ;
        for(char c : s){
            if(c == '(') {
                open++ ;
            }else if(c == ')'){
                close++ ;
            }
            if(open == close){
                result = max(result , open + close );
            }else if(close > open){
                open = 0 ;
                close = 0 ;
            }
        }
        if(s.size() == result){
            return result ;
        }
        int n = s.size() ;
        open = 0 , close = 0 ;
        for(int i = n -1 ; i >= 0 ; i--){
            if(s[i] == ')'){
                close++ ;
            }else if(s[i] == '('){
                open++ ;
            }
            if(open == close){
                result = max(result , open + close );
            }else if(close < open){
                open = 0 ;
                close = 0 ;
            } 
        }
        return result ;
    }
};