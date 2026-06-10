class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size() ;
        vector <vector<int>> dist(n,vector<int> (m,INT_MAX)) ; 

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;
        
        pq.push({0,{0,0}}) ; 
        vector <pair<int,int>> move ={ {0,1} , {0,-1} , {1,0} ,{-1,0} } ; 
        dist[0][0] = 0 ; 
        while(pq.size() != 0){
            auto pp = pq.top() ; 
            pq.pop() ; 
            int diff = pp.first , x = pp.second.first , y = pp.second.second ; 
            //cout<<x<<" "<<y<<" "<<endl;
            if(x == n-1 && y == m-1 ) return diff ; 
            for(auto [dx , dy] : move){
                int nx = x + dx ; 
                int ny = y + dy ; 
                //cout<<nx<<" "<<ny<<" ";
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && 
                max(abs(grid[x][y] - grid[nx][ny]) , dist[x][y]) < dist[nx][ny] ){
                    dist[nx][ny] = max(abs(grid[x][y] - grid[nx][ny]) , dist[x][y]) ; 
                    pq.push({dist[nx][ny] , {nx ,ny}}) ;
                }
            }
        }
        return dist[n-1][m-1] ;
        
    }
};