class Solution {
public:
    int maximum69Number (int num) {
        string s = "" ;
        bool flag = true ; 
        int n = num ; 
        while(n > 0){
            string temp = to_string(n%10) ; 
            s = temp + s ;
            n /= 10 ;
        }
        for(int i =0 ; i<s.length() ; i++){
            if(s[i] == '6' && flag){
                s[i] = '9' ;
                flag = false ;
            }
        }
        return stoi(s) ;
    }
};