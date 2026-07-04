class Solution {
public:
    int n ;
    int m ; 
    void change_rows(vector<vector<int>>& v , int r){
        for(int i = 0 ; i < m ; i++){
            v[r][i] = 0 ;
        }
    }
    void change_cols(vector<vector<int>>& v , int c){
        for(int i = 0 ; i < n ; i++){
            v[i][c] = 0 ;
        }
    }
    void setZeroes(vector<vector<int>>& v) {
        n = v.size() , m = v[0].size() ;
        vector <bool> rows(n,0) , cols(m,0) ; 
        for(int i = 0 ; i < n ; i ++){
            for(int j= 0 ; j < m ; j++){
                if(v[i][j] == 0 ){
                    rows[i] = 1 ;
                    cols[j] = 1 ;
                }
            }
        } 
        for(int i = 0 ; i < n ;i++){
            if(rows[i]) change_rows(v,i) ; 
        }
        for(int i = 0 ; i < m ;i++){
            if(cols[i]){
                change_cols(v,i) ;
            } 
        }
        
    }
};