class Solution {
public:
    int numSteps(string s) {
        int c = 0 ;
        while(s != "1"){
            int n = s.length() ; 
            if(s[n - 1] == '1'){
                int carry = 1 ;
                for(int i = n-1 ; i>= 0 ;i--){
                    if(carry == 0) break ;
                    if(s[i] == '0'){
                        s[i] = '1' ; 
                        carry = 0 ; 
                    }
                    else if(s[i] == '1') s[i] = '0' ; 
                }
                if(carry) s = "1" + s ;
            }
            else s.erase(n-1,1) ;
            c++;
        }
        return c; 
        
    }
};