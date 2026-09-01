class Solution {
public:
    vector <vector<vector<int>>> dp ; 
    vector <pair<int,int>> moves = {{1,0} , {-1,0} , {0,1} ,{0,-1}} ; 
    bool solve(int x , int y,int idx,string word,vector<vector<char>>& board){
        int n = board.size() , m = board[0].size() ; 
        if(idx +1 == word.size() && board[x][y] == word[idx]) return true ;
        if(board[x][y] != word[idx]) return false ;
        //if(dp[x][y][idx] != -1) return dp[x][y][idx] ; 
        char temp = board[x][y] ; 
        board[x][y] = '*' ; 
        for(int i = 0 ; i < 4 ; i++){
            int nx = x + moves[i].first ;
            int ny = y + moves[i].second ;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] != '*'){
                bool ans = solve(nx , ny , idx +1 , word , board) ; 
                if(ans) return ans ; 
            }
        }
        board[x][y] = temp ; 
        //return dp[x][y][idx] =false; 
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size() , m = board[0].size() ; 
        //dp.resize(n+ 4 ,vector <vector<int>>(m+5 , vector<int> (word.size() + 1, -1))) ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == word[0]){
                    bool ans = solve(i ,j ,0 ,word ,board) ; 
                    if(ans) return ans ; 
                }
            }
        }
        return false  ;   
    }
};