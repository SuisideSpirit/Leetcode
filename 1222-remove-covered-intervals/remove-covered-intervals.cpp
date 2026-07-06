class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& v) {
        int n = v.size() ; 
        int ans = 0 ; 
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == j) continue ;
                int a = v[i][0] , b = v[i][1] ;
                int c = v[j][0] , d = v[j][1] ;
                if(c <= a && b <= d){
                    ans++ ;
                    break ;
                }
            }
        }
        return n - ans ;
        
    }
};