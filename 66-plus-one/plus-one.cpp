class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() ; 
        bool carry = true ; 
        for(int i = n-1 ; i >= 0 ; i--){
            if(!carry) continue ;
            if(digits[i] == 9){
                digits[i] = 0 ;
                carry = true ;
            }
            else {
                digits[i] += 1 ;
                carry = false;
            }
        }
        if(carry)digits.insert(digits.begin(), 1);
        return digits ;
    }
};