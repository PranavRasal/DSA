class Solution {
public:
    void helper(unordered_set<string>& st ,queue<string>& qu , string& cha ){
        for(int i = 0 ; i < 4 ; i++){
            char word = cha[i] ;
            char inc = word == '9' ? '0' : word + 1;
            char dec = word == '0' ? '9' : word - 1 ;
            cha[i] = inc ;
            if(st.find(cha) == st.end()){
                st.insert(cha) ;
                qu.push(cha) ;
            }
            cha[i] = dec ;
            if(st.find(cha) == st.end()){
                st.insert(cha) ;
                qu.push(cha) ;
            }
            cha[i] = word ;
        }
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(deadends.begin() , deadends.end()) ;
        string start = "0000" ;
        if(st.find(start) != st.end()){
            return -1 ;
        }
        st.insert(start) ;
        queue<string> qu ;
        qu.push(start) ;
        int level = 0 ;
        while(!qu.empty()){
            int n = qu.size() ;
            while(n--){
                string ch = qu.front() ;
                qu.pop() ;
                if(ch == target){
                    return level ;
                }
                helper(st , qu , ch) ;
            }
            level++ ;
        }
        return -1 ;
    }
};