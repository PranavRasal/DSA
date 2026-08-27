class Solution {
public:
    string ans = "" ;
    bool solve(vector<int>& count, string target , int i , bool great , string& curr){
        if(i == target.size()){
            if(great){
                ans = curr ;
                return true ;
            }
            return false ;
        }
        for(char ch = 'a' ; ch <= 'z' ;  ch++){
            if(count[ch - 'a'] == 0 ) continue ; 
            if(!great && ch < target[i]) continue ;

            curr.push_back(ch) ;
            count[ch - 'a']-- ;

            bool gret = great ;
            if(ch > target[i]){
                gret = true ;
            }
            if(solve(count , target , i + 1 , gret , curr )) {
                return true ;
            }
            curr.pop_back() ;
            count[ch - 'a']++ ;
        }
        return false ;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int>count(26 , 0) ;
        for(int i = 0 ; i < s.size() ; i++){
            count[s[i] - 'a']++ ;
        }
        string curr = "" ;
        if(solve(count , target , 0 , false , curr )){
            return ans ;
        }
        return "" ;
    }
};