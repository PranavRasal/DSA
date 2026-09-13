class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0 ;
        for(int i = s.size() -1 ; i >= 0 ; i--){
            if(isalpha(s[i])){
               count++ ;
               continue ;
            }else if (count > 0) break ;
            
        }
        return count ;
    }
};