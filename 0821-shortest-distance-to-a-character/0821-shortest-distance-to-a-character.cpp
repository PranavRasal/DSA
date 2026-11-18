class Solution {
public:
    int findDis(string s , char c , int i){
        int left = INT_MAX ;
        int right = INT_MAX ;
        int count = 1 ;
        for(int j = i-1 ; j >= 0 ; j--){
            if(s[j] == c){
                left = count ;
                break ;
            }
            count++ ;
        }
        count = 1 ;
        for(int j = i + 1 ; j < s.size() ; j++){
           if(s[j] == c){
                right = count ;
                break ;
            }
            count++ ; 
        }
        return min(left , right) ;
    }
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans(s.size() , -1) ;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == c){
                ans[i] = 0 ;
                continue ;
            }
            ans[i] = findDis(s , c , i) ;
        }
        return ans ;
    }
};