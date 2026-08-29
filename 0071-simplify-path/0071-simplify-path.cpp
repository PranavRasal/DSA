class Solution {
public:
    string simplifyPath(string path) {
        int num = 0 ;
        vector<string>store( path.size() , "") ;
        for(int i = 0 ; i < path.size() ; i++){
            if(path[i] == '/'){
                if(!store[num].empty()) {
                    num++;} continue ;
            }else{
                 store[num] += path[i] ;}}
        stack<string>st ;
        for(int i = 0 ; i < store.size() ; i++ ){
            if(store[i] == "." || store[i] == ""){
                continue ;
            }else if(store[i] ==".." ){
                if(st.size() > 0){
                st.pop() ; }
            }else{
                st.push(store[i]) ;
            }}
        string result = "";
        if(st.empty()){
            return "/" ;
        }
        while(!st.empty()){
            result =  "/" + st.top() + result ;
            st.pop() ; }
        return result ;
    }
};