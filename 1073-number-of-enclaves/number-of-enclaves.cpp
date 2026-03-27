class Solution {
public:
    typedef pair<int,int> pp ;
    int numEnclaves(vector<vector<int>>& v) {
        int n = v.size() ;
        int m = v[0].size() ;
        queue <pp> q ;
        int land = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(v[i][j] == 1) land++;
                if(v[i][j] == 1 && (i == 0 || i == n-1 || j == 0 || j == m-1 )){
                    q.push({i,j}) ; 
                    land--;
                    v[i][j] = 0 ; 
                }
            }
        }
        if(land ==0) return 0 ;
        while(q.size() != 0){
            pp curr = q.front() ;
            int x = curr.first; 
            int y = curr.second ;
            q.pop() ;
            if(x!= n-1 && v[x+1][y] == 1){
                q.push({x+1,y}) ;
                v[x+1][y] = 0 ; 
                land--;
            }
            if(x!= 0 && v[x-1][y] == 1){
                q.push({x-1,y}) ;
                v[x-1][y] = 0 ; 
                land--;
            }
            if(y!= 0 && v[x][y-1] == 1){
                q.push({x,y-1}) ;
                v[x][y-1] = 0 ; 
                land--;
            }
            if(y!=m-1 && v[x][y+1] == 1){
                q.push({x,y+1}) ;
                v[x][y+1] = 0 ; 
                land--;
            }
            if(land == 0 ) return 0 ;
        }
        return land ;
    }
};