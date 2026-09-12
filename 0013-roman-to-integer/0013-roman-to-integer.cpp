class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char , int > roman;
        roman['I'] = 1 ;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C']  = 100;
        roman['D'] =  500;
        roman['M'] = 1000;
        int num = 0 ; 
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == 'I'&& i + 1 != s.size() &&(s[i+1] == 'V' || s[i+1] == 'X')){
                num += roman[s[i+1]] - roman[s[i++]] ;
            }else if(s[i] == 'X'&& i + 1 != s.size() &&(s[i+1] == 'L' || s[i+1] == 'C')){
                num += roman[s[i+1]] - roman[s[i++]] ;
            }else if(s[i] == 'C'&& i + 1 != s.size() &&(s[i+1] == 'D' || s[i+1] == 'M')){
                num += roman[s[i+1]] - roman[s[i++]] ;
            }else {
                num += roman[s[i]] ;
            }
        }
        return num ;
    }
};