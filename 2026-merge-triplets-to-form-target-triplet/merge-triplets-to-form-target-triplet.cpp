class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& tri, vector<int>& target) {
        int n = tri.size() ; 
        int a = target[0] , b = target[1] , c = target[2] ; 
        int ta = -1 , tb = -1 , tc = -1  ;
        for(auto ele : tri){
           if(ele[0] <= a && ele[1] <= b && ele[2] <= c) {
            ta = max(ta ,ele[0]) ; 
            tb = max(tb , ele[1]) ;
            tc = max(tc , ele[2]) ;
           }  
        }
        if(ta == a && tb == b && tc == c) return true ; 
        return false; 
        
    }
};