class Solution {
public:
    void check(queue<string>& qu  ,queue<string>& sto , string word){
        int n = sto.size() ;
        for(int i = 0 ; i < n ; i++){
            int chance = 1 ;
            string wordCheck = sto.front() ;
            sto.pop() ;
            if(wordCheck.size() != word.size()){
                sto.push(wordCheck) ;
                continue ;
            }
            int valid = true ;
            for(int j = 0 ; j < word.size() ; j++){
                if(wordCheck[j] != word[j] && chance == 1){
                    chance-- ;
                }else if(wordCheck[j] != word[j] && chance == 0){
                    valid = false ;
                    break ;
                }
            }
            if(valid && chance == 0){
                qu.push(wordCheck) ;
            }else{
                sto.push(wordCheck) ;
            }
        }
        
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> qu;
    queue<string> sto;

    

    for(int i = 0; i < wordList.size(); i++){
        sto.push(wordList[i]);
    }

    qu.push(beginWord);

    int lev = 1;

    while(!qu.empty()){

        int n = qu.size();

        for(int i = 0; i < n; i++){

            string word = qu.front();
            qu.pop();

            if(word == endWord){
                return lev;
            }

            check(qu, sto, word);
        }

        lev++;
    }

    return 0;
    }
};