class Solution {
public:
    bool check(int minR ,int maxR ,int minC , int maxC ,vector<vector<char>>& board){
        vector <bool> v(10,false) ; 
        bool ans = true ;
        for(int i =minR;i<=maxR ; i++){
            for(int j = minC ; j <= maxC ; j++ ){
                if(board[i][j] != '.'){
                    if(v[board[i][j] - '0'] ){
                        ans = false ; 
                        break ;
                    }
                    v[board[i][j] - '0'] = true ;
                }
            }
        }
        return ans ;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans = true ;
        int n = 9;
        for(int i = 0 ; i < n ; i++){
            if(!check(i,i,0,8,board)) return false ;
        }
        for(int i = 0 ; i < n ; i++){
            if(!check(0,8,i,i,board)) return false ;
            
        }
        for(int i = 0 ; i < n ; i+=3){
            for(int j = 0 ; j<n ;j+=3){
                if(!check(i,i+2,j,j+2,board)) return false ;
            }
        }
        return ans ;
        
    }
};