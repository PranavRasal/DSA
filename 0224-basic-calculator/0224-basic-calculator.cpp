class Solution {
public:
    int calculate(string s) {
        long long number = 0 ;
        long long result = 0 ;
        int sign = 1 ;
        stack<long long> st ;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == ' '){
                continue ;
            }
            if(s[i] == '('){
                result += number * sign ;
                number = 0 ;
                st.push(result) ;
                result = 0 ;
                st.push(sign) ;
                sign = 1 ;
            }else if(s[i] == ')'){
                result += number * sign ;
                long long sign2 = st.top() ; 
                st.pop() ;
                long long value = st.top() ;
                st.pop() ;
                result = value + result  * sign2 ;
                number = 0 ;
                sign = 1 ;
            }
            else if(s[i] == '-'){
                result += number * sign ;
                number = 0 ;
                sign = -1 ;
            }else if(s[i] == '+'){
                result += number * sign ;
                number = 0 ;
                sign = 1 ;
            }else{
                number = (number * 10) + (s[i] - '0') ;
            }
        }
        return result + number * sign;
    }
};