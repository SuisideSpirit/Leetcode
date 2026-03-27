class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size() ; 
        int m = mat[0].size() ; 
        if(k%m == 0) return true ;
        vector <vector<int>> check(n,vector <int> (m)); 
        for(int i = 0 ; i < n;i++){
            for(int j = 0 ;j < m ; j++){
                check[i][j] = mat[i][j] ; 
            }
        }
        k = k%m ; 
        for(int i = 0 ; i < n ; i++){
            if(i%2 == 0){
                for(int j = 0 ; j < m ;j++){
                    mat[i][j] = check[i][(j+k)%m] ;
                }
            }
            else{
                for(int j = 0 ; j < m ;j++){
                    int idx = (j-k)%m ;
                    if(idx < 0) idx += m;
                    mat[i][j] = check[i][idx] ;
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                cout<<mat[i][j]<<" "<<check[i][j]<<endl;
                if(mat[i][j] != check[i][j]) return false;
            }
        }
        return true ;    
    }
};