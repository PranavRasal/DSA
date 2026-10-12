class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int > mp ;

        for(int i = 0 ; i < s.size() ; i++){
            mp[s[i]]++ ;
        }
        int ans = 0 ;
        bool rem = false ;
        for(auto it : mp){
            ans += (it.second / 2) * 2 ;
            if(it.second % 2 == 1){
                rem = true ;
            }
        }
        if(rem ){
            ans++ ;
        }
        return ans ;
    }
};