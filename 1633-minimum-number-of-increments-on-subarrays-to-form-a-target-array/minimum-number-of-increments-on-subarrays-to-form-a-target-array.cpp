class Solution {
public:
    int minNumberOperations(vector<int>& v) {
        // i want rectangle with the longest base 
        int n = v.size() ; 
        int op = 0 ; 
        int curr = 0 ; 
        int prev = 0 ; 
        for(int i = 0 ; i < n ;i++){
            int curr = v[i] ; 
            if(curr > prev){
                op += curr - prev ; 
            }
            prev = v[i] ;
        }
        return op ; 
    }
};