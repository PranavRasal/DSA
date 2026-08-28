class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "" ;
        }
        if(strs.size() == 1){
            return strs[0] ;
        }
        string ans = strs[0] ;
        string one = strs[0] ;
        
        for(int i = 1 ; i < strs.size() ; i++){
            string two = strs[i] ;
            int j = 0 ;
            while(j < strs[i].size() && j < one.size() && one[j] == two[j]){
                j++ ;
            }
            if(j == 0 ){
                return "" ;
            }
            ans = ans.substr(0 , j) ;
            
        }
        return ans ;
    }
};