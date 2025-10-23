class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length() ; 
        int curr = 0 ;
        for(int j =0 ;j<n-2 ;j++){
            string temp = "";
            for(int i = 1; i<s.length() ;i++){
                int add = ((int)s[i] - '0')  + ((int)s[i-1] - '0') ;
                add = add%10 ;
                temp = temp + to_string(add) ;
            }
            s = temp ;
        }
        if(s[0] == s[1]) return true ;
        return false;
        
    }
};