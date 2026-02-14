class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector <vector <double>> v(105,vector <double> (105,0)) ; 
        v[0][0] = poured ; 
        for(int i= 0 ; i <= 100 ; i++){
            for(int j = 0 ; j <= i ; j++){
                if(v[i][j] >= 1.000){
                    v[i+1][j] += (v[i][j] - 1.000)/2.0 ; 
                    v[i+1][j+1] += (v[i][j] - 1.000)/2.0 ;
                    v[i][j] = 1.000 ;
                }
            }
        }
        return min(1.0,v[query_row][query_glass]) ;
        
    }
}; 