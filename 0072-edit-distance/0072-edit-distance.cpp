class Solution {
public:
    vector<vector<int>> dp ;
    int helper(string word1, string word2 , int i , int j){
        if(dp[i][j] != -1){
            return dp[i][j] ;
        }
        if(i == word1.size()){
            return dp[i][j] = word2.size() - j ;
        }
        if(j == word2.size()){
            return dp[i][j] = word1.size() - i ;
        }
        if(word1[i] == word2[j]){
            return dp[i][j] = helper(word1 , word2 , i + 1 , j + 1 ) ;
        }
        int edit = helper(word1 , word2 , i + 1 , j + 1 )  +  1 ;
        int del = helper(word1 , word2 , i + 1 , j  ) + 1;
        int insert = helper(word1 , word2 , i , j+1  ) + 1 ;
        return dp[i][j] = min({edit , del , insert}) ;
    }
    int minDistance(string word1, string word2) {
        dp.assign(word1.size() + 1, vector<int>(word2.size()+ 1 , -1)) ;
        return helper(word1 , word2 , 0 , 0 ) ;
    }
};