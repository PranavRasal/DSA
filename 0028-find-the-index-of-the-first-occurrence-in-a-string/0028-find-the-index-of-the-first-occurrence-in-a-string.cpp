class Solution {
public: 
    bool check(string a , string b , int num){
        int j = 0 ;
        for(int i = num ; i < a.size() && j < b.size(); i++){
           if( a[i] == b[j++]){
            continue ;
           }
           return false ;
        }
        if ( j == b.size()){
            return true ;
        }
        return false ;
    }
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()){
            return -1 ;
        }
        for(int i = 0 ; i < haystack.size() ; i++ ){
            if(haystack[i] == needle[0]){
                bool ans = check(haystack , needle , i) ;
                if (ans){
                    return i ;
                }
            }
        }
        return -1 ;
    }
};