class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> stor(26 , 0) ;
        int j = 0 ;
        int n = s.size() ;
        int ans = INT_MIN ;

        for(int i = 0 ; i < n ; i++){
            int with = i - j + 1;
           stor[s[i] - 'A']++ ;
           int maxWith = 0 ;
           for(int k = 0 ; k < 26 ; k++){
                maxWith = max(maxWith , stor[k]) ;
           }
           int charReplace = with - maxWith ;
           if(charReplace > k){
            stor[s[j] - 'A']-- ;
            j++ ;
            with-- ;
            // for(int k = 0 ; k < 26 ; k++){
            //     maxWith = max(maxWith , stor[k]) ;
            // }
            // charReplace = with - maxWith ;
           }
           ans = max(with , ans) ;
        }
        return ans ;
    }
};