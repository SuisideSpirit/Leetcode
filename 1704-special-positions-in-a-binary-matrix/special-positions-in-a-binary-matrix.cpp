class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size() ; 
        int m = mat[0].size() ; 

        vector <vector<bool>> ans(n ,vector <bool> (m,true)) ; 

        for(int i = 0 ; i< n ; i++){
            int pos = -1 ; 
            for(int j = 0 ; j < m ; j++){
                if(pos == -1 && mat[i][j] == 1){
                    pos = j ; 
                }
                else if(pos > -1 && mat[i][j] == 1){
                    ans[i][pos] = false;
                    pos = -2; 
                    ans[i][j] = false;
                }
                else {
                    ans[i][j] = false;
                }
            }
        }
        for(int j = 0 ; j<m; j++){
            int pos = -1 ; 
            for(int i = 0 ; i<n ; i++){
                if(pos == -1 && mat[i][j] == 1){
                    pos = i ; 
                }
                else if(pos > -1 && mat[i][j] == 1){
                    ans[pos][j] = false;
                    pos = -2; 
                    ans[i][j] = false;
                }
                else {
                    ans[i][j] = false;
                }
            }
        }
        int c = 0 ; 
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(ans[i][j]) c++; 
            }
        }
        return c;
        
    }
};