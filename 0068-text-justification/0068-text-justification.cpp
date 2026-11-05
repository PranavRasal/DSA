class Solution {
public:
    string justify(int st , int end , int eachSpace , int extraSpace , vector<string>& words){
        string ans ;
        for(int i = st ; i <= end ; i++){
            ans += words[i] ;
            if(i < end){
                ans += string(eachSpace , ' ') ;
                if(extraSpace > 0){
                    ans += " " ;
                    extraSpace-- ;
                }
            }
        }
        return ans ;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i = 0 ;
        int n = words.size() ;
        vector<string> ans;
        while(i < n){
            int lenOfLine = words[i].size() ;
            int j = i + 1 ;
            int space = 0 ;
            while(j < n && lenOfLine + space + words[j].size() + 1 <= maxWidth){
                lenOfLine += words[j++].size() ;
                space++ ;
            }
            if(j == n || j - i == 1){
                string line = "" ;
                for(int k = i ; k < j ; k++){
                    line += words[k] ;
                   if(k < j - 1) {
                        line += " ";
                    }
                }
                line += string(maxWidth - line.size() , ' ') ;
                ans.push_back(line) ;
            }else {
            int totalWord = j - i;
            int gaps = totalWord - 1;

            int remSpace = maxWidth - lenOfLine;
            int eachSpace = remSpace / gaps;
            int extraSpace = remSpace % gaps;
            ans.push_back(justify(i , j-1 ,eachSpace , extraSpace , words ));
            }
            i = j ;
            
        }
        return ans ;
    }
};