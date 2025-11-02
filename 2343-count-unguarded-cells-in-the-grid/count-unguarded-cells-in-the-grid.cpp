class Solution {
public:
    void fill(int m, int n ,int i , int j ,vector<vector<int>> &Check){
        vector <int> X = {1,-1,0,0} ;
        vector <int> Y = {0,0,1,-1} ;

        for(int z = 0 ; z<=3 ;z++){
            int x = X[z] ; 
            int y = Y[z] ;
            int currX = i ;
            int currY = j ; 
            currX += x ;
            currY += y ;
            while((currX >= 0 && currX < m )&& (currY >= 0 && currY < n)){
                if(Check[currX][currY] == 2  || Check[currX][currY] == 3) break ;
                Check[currX][currY] = 1 ;
                currX += x ;
                currY += y ;
            }
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> Check(m,vector <int> (n,0)) ;   

        for(int i =0 ; i<walls.size() ; i++){
            Check[walls[i][0]][walls[i][1]] = 3;
        }
        for(int i =0 ; i<guards.size() ; i++){
            Check[guards[i][0]][guards[i][1]] = 2  ;  
        }
        for(int i =0 ; i<guards.size() ; i++){
            fill(m,n,guards[i][0],guards[i][1] , Check) ; 
        }
        int ans = 0 ;
        for(int i = 0; i < m ; i++){
            for(int j = 0 ; j<n ;j++){
                if(Check[i][j] == 0){
                    ans += 1; 
                }
            }
            cout<<endl;
        }
        return ans ;
    }
};