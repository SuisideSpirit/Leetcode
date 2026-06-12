class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue< pair<int,pair<int,int>>,
        vector <pair<int,pair<int,int>>>,
        greater <pair<int,pair<int,int>>>> pq ;
        int n = grid.size() ; 
        vector<vector<int>> visited(n,vector <int> (n,0)) ; 
        int ans = grid[0][0] ; 
        pq.push({0,{0,0}}) ;
        vector <pair<int,int>> moves = {{1,0} , {0,1} , {-1,0} , {0,-1}} ;  
        visited[0][0] = 1 ;
        while(pq.size() != 0){
            auto p = pq.top() ; 
            pq.pop() ;
            int cur = p.first , x = p.second.first , y = p.second.second ; 
            ans = max(ans,cur) ; 
            if(x == n-1 && y == n-1) return ans ;
            for(auto [dx,dy] : moves){
                int nx = x + dx ; 
                int ny = y + dy ; 
                if(nx >= 0 && ny >= 0 && nx < n && ny < n && visited[nx][ny] == 0){
                    visited[nx][ny] = 1 ;
                    pq.push({grid[nx][ny], {nx,ny}}) ;
                }
            }
        }
        return ans ;

        
    }
};