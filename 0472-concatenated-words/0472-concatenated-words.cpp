class Solution {
public:
    unordered_map<string , bool> mp ;
    bool helper(string word , unordered_set<string>& st){
        if(mp.find(word) != mp.end()){
            return mp[word] ;
        }
        int n = word.size() ;
        for(int i = 0 ; i < n ; i++){
            string pre = word.substr(0 , i+ 1) ;
            string post = word.substr(i+1 ) ;
            if( (st.find(pre) != st.end() && st.find(post) != st.end()) ||
             (st.find(pre) != st.end() && helper(post , st)) ){
                return mp[word] = true ;
             }
        }
        return mp[word] = false ;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(begin(words) , end(words)) ;
        vector<string> ans ;
        int n = words.size() ;
        for(int i = 0 ; i < n ; i++){
            string word = words[i] ;
            if(helper(word , st)){
                ans.push_back(word) ;
            }
        }
        return ans ;
    }
};