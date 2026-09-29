class Solution {
public:
    string reverseParentheses(string s) {
        vector<char> word ;
        stack<int> st ;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '('){
                st.push(word.size()) ;
                continue ;
            }
            if(s[i] == ')'){
                reverse(word.begin() + st.top() , word.end()) ;
                st.pop() ;
                continue ;
            }
            word.push_back(s[i]) ;
        }
        string ans ;
        for(int i = 0 ; i < word.size() ; i++){
            ans = ans + word[i] ;
        }
        return ans ;
    }
};