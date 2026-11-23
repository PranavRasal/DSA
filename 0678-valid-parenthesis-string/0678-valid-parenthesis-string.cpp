class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open ;
        stack<int> star ;
        int chance = 0 ; 
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '*'){
               star.push(i) ;
            }else if(s[i] == '('){
                open.push(i) ;
            }else{
                if(open.size() > 0){
                    open.pop() ;
                }else if(star.size() > 0){
                    star.pop() ;
                }else{
                    return false ;
                }
            }
        }
        while(!open.empty()){
           if(star.empty() || open.top() > star.top()){
                return false ;
            }
            open.pop() ;
            star.pop() ;
                
            
        }
        return true ;
    }
};