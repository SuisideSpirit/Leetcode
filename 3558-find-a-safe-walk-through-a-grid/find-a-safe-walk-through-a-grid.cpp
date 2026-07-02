class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size()  ; 
        int m = grid[0].size() ; 
        priority_queue<pair<int, pair<int,int>>> pq;
        pq.push({health,{0,0}}) ;
        vector <vector<int>> visited(n,vector <int> (m ,0)) ;
        vector <pair<int,int>> moves = {{1,0} , {-1,0} , {0,1} , {0,-1}} ; 
        visited[0][0] =1 ;  
        while(pq.size() != 0 ){
            auto ele = pq.top() ;
            int h = ele.first ; 
            int x = ele.second.first , y = ele.second.second ; 
            pq.pop() ; 
            if(grid[x][y] == 1) h-- ; 
            if(h <= 0 ) continue ;
            if(x == n-1 && y == m-1) return true ;
            for(auto ele : moves){
                int nx = ele.first + x ; 
                int ny = ele.second + y ; 
                if(nx >= 0 && nx < n && ny < m && ny >= 0 && visited[nx][ny] < h){
                    pq.push({h,{nx,ny}}) ; 
                    visited[nx][ny] = h ;
                }
            }
        }
        return false ;
    }
};