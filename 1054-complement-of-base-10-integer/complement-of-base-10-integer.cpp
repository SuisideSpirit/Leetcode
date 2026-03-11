class Solution {
public:
    int bitwiseComplement(int n) {
        string s = "" ; 
        while(n > 0 ){
            if(n%2 == 0 ) s = '1' + s ;
            else s = '0' + s ;
            n/=2 ;
        }
        if(s == "") s = "1";
        int mult = 1 ;
        int ans = 0;
        for(int i = s.size()-1 ; i >= 0 ; i--){
            if(s[i] == '1') ans += mult ; 
            mult *= 2; 
        }
        return ans;
    }
};