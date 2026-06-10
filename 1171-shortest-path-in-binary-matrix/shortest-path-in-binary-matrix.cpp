class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() ; 
        vector <pair<int,int>> moves = {{1,1},{1,-1},{-1,1},{-1,-1},{0,1},{0,-1},{1,0},{-1,0}} ;
        if(grid[0][0] == 1) return -1 ;
        vector <vector<int>> dist(n,vector <int> (n,INT_MAX)) ; 
        priority_queue <pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> q ; 
        q.push({0,0}) ;
        dist[0][0] = 1 ;
        while(q.size() != 0 ){
            auto pp = q.top() ; 
            q.pop() ;
            int x = pp.first , y = pp.second ; 
            if(x == n-1 && y == n-1 ) break ;
            for(auto [dx ,dy] : moves){
                int nx = x + dx ; 
                int ny = y + dy ; 
                if(nx >= 0 && ny >= 0 && nx < n && ny < n &&
                dist[x][y] + 1 < dist[nx][ny] && grid[nx][ny] == 0){
                    dist[nx][ny] = dist[x][y] + 1  ; 
                    q.push({nx,ny}) ; 
                }
            }
        }
        if(dist[n-1][n-1] == INT_MAX) return -1; 
        return dist[n-1][n-1] ; 

        
    }
};