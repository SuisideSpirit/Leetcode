class Solution {
public:
    vector <vector<char>> f ; 
    bool solve(int i, int j , vector <vector<char>> &board , unordered_map <int,vector <int>>&ver, 
    unordered_map <int,vector <int>> &hor , unordered_map <int,vector <int>> &block){
        if(i == 9 ){
            f = board ; 
            return true ; 
        }
        bool ans = false ;
        if(board[i][j] != '.'){
            if(j == 8) ans = solve(i + 1 , 0 , board , ver , hor , block) ; 
            else ans = solve(i , j + 1 ,board , ver , hor , block) ; 
            return ans ; 
        }
        int row = i/3 , col = j/3 ; 
        for(int num = 1 ; num <= 9 ; num++){
            if(ver[i][num] == 1) continue ; 
            if(hor[j][num] == 1) continue ; 
            if(block[row*10 + col][num] == 1) continue ;

            ver[i][num] = 1 ;
            hor[j][num] = 1 ; 
            block[row*10 + col][num] = 1 ;
            board[i][j] = '0' + num ; 

            if(j == 8) ans = solve(i + 1 , 0 , board , ver , hor , block) ; 
            else ans = solve(i , j + 1 ,board , ver , hor , block) ; 

            if(ans) return ans ; 

            ver[i][num] = 0 ;
            hor[j][num] = 0 ; 
            block[row*10 + col][num] = 0 ;
            board[i][j] = '.';
        }
        return false ;
    }
    void solveSudoku(vector<vector<char>>& board) {
        unordered_map <int,vector <int>> ver ; 
        unordered_map <int,vector <int>> hor ;
        unordered_map <int,vector <int>> block ; 
        vector <int> v(10 , 0 ) ; 
        for(int i = 0 ; i < 9; i++) ver[i] = v ; 
        for(int i = 0 ; i < 9 ; i++) hor[i] = v; 
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                block[i*10 + j] = v ; 
            }
        }
        for(int i = 0 ; i < 9 ; i ++){
            for(int j = 0 ; j < 9 ; j++){
                if(board[i][j] == '.') continue ;
                int idx = board[i][j] - '0' ;
                int r = i/3 , c = j/3 ;  
                ver[i][idx] = 1 ; 
                hor[j][idx] = 1 ; 
                block[r*10 + c][idx] = 1 ;
            }
        }
        solve(0,0,board , ver ,hor ,block) ;
    }
};