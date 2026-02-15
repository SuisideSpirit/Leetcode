class Solution {
public:
    string addBinary(string a, string b) {
        int n = max(a.size(),b.size()) ;
        int l1 = n - a.size();
        int l2 = n - b.size();
        for(int i = 0; i <l1; i++){
            a = "0" + a; 
        }
        for(int i = 0; i <l2; i++){
            b = "0" + b; 
        }
        int carry = 0 ;
        string ans = "";
        for(int i = n-1; i >= 0; i--){
            int temp = 0 ;
            if(carry) temp += 1 ;
            if(a[i] == b[i] && a[i] == '1') temp += 2 ;
            else if(a[i] != b[i]) temp++;
            if(temp == 0){
                carry = 0 ;
                ans = '0' + ans ;
            }
            else if(temp == 1){
                carry = 0 ;
                ans = '1' + ans ;
            }
            else if(temp == 2){
                carry = 1 ;
                ans = '0' + ans ;
            }
            else {
                carry = 1 ;
                ans = '1' + ans; 
            }
        }
        if(carry) ans = '1' + ans ; 
        return ans;
        
    }
};