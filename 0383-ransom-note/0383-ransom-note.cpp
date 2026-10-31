class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size()){
            return false ;
        }
        vector<int> ransome(26 , 0) ;
        vector<int> maga(26 , 0) ;
        for(int i = 0 ; i < ransomNote.size() ; i++){
            ransome[ransomNote[i] - 'a']++ ;
        }
        for(int i = 0 ; i < magazine.size() ; i++){
            maga[magazine[i] - 'a']++ ;
        }
        for(int i = 0 ; i < 26 ; i++){
            if(maga[i] < ransome[i]){
                return false ;
            }
        }
        return true ;
    }
};