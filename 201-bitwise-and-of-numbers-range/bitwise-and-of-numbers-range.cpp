class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shifts = 0 ;
        while(left < right){
            left = left>>1 ; 
            right = right>>1 ; 
            shifts++;
        } 
        return left<<shifts;
    }
};