class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x) ;
        string a = s ;
        reverse(a.begin() , a.end()) ;
        return a == s ;
    }
};