class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        stack<int> st ;
        int n = digits.size() ;
        int carry = 0 ; 
        for(int i = n -1 ; i >= 0 ; i--){
            int num = digits[i] ;
            if( i == n -1 ){
                num += 1 ; 
            }
            if(num + carry == 10){
                carry = 1 ;
                st.push(0) ;
                continue ;
            }
            st.push(num + carry) ;
            carry = 0 ;
        }
        if(carry){
            st.push(1) ;
        }
        vector<int> ans ;
        while(st.size() > 0){
            ans.push_back(st.top());
            st.pop() ;
        }
        return ans ;
    }
};