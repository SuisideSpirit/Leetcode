class Solution {
public:
    long long OverlapArea(vector <int> &b1 ,vector <int> &b2,vector <int> &u1,vector <int> &u2){

        int overlapX = 0 ; 
        int overlapY = 0 ;  
        int sx1 = b1[0] ;int sy1 = b1[1] ; 
        int sx2 = b2[0] ;int sy2 = b2[1] ;
        int ex1 = u1[0] ;int ey1 = u1[1] ; 
        int ex2 = u2[0] ;int ey2 = u2[1] ; 
        overlapX = max(0,min(ex1 , ex2) - max(sx2,sx1)) ;
        overlapY = max(0,min(ey1 , ey2) - max(sy2,sy1)) ;
        return min(overlapX , overlapY) ;

    }
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size() ; 
        long long ans = 0 ;
        for(int i = 0 ; i < n; i++){
            for(int j= i+1; j<n ; j++){
                long long temp = OverlapArea(bottomLeft[i] , bottomLeft[j] ,
                                             topRight[i] , topRight[j]) ; 
                ans = max(ans,temp) ;
            }
        }
        return ans*ans ;
        
    }
};