class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size() ; 
        long long sum = 0 ;
        long long sqSum = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                sum += grid[i][j] ;
                sqSum += (grid[i][j]*grid[i][j]) ;
            }
        }
        long long reqSum = 0 , reqSqSum = 0 ; 
        for(int i = 1 ;  i<= n*n ; i++){
            reqSum += i ; 
            reqSqSum += i *i ; 
        }
        int diff = sum - reqSum ; 
        int summation = (reqSqSum - sqSum)/diff ; 
        int missing = (diff + summation)/2 ; 
        int rep= (diff - summation)/2  ; 
        return {rep , -missing} ; 

        
    }
}; 