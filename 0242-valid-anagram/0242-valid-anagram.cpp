class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false ;
        }
        vector<int>sLetter(26 , 0) ;
        vector<int>tLetter(26 , 0) ;
        for(int i = 0 ;  i < s.size() ; i++){
           
            sLetter[s[i] - 'a']++ ;
            tLetter[t[i] - 'a'] += 1 ;
        }
        return sLetter == tLetter ;
    }
};