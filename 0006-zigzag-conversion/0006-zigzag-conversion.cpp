class Solution {
public:
    string convert(string s, int numRows) {

         if(numRows == 1 || numRows >= s.size()) {
            return s;
        }

       vector<string> stor(numRows , "") ;

       int i = 0 ; 

       while(i < s.size()){

        //strain line
        for(int j = 0 ; j < numRows && i <  s.size(); j++ , i++){
            stor[j].push_back(s[i]) ;
            }

        //diagonal line 
        for(int j = numRows - 2 ; j > 0 && i <  s.size() ; j-- , i++){
            stor[j].push_back(s[i]) ;
            }
        }
       string ans = "" ;
       for(int j = 0 ; j < numRows ; j++){
        ans += stor[j] ;;
       }
       return ans ;
    }
};