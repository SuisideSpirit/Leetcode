class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector <vector<int>> dist(n,vector<int> (n,1e8)) ; 
        for(int i =0 ;i < n ;i++) dist[i][i] = 0 ;
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0] , v = edges[i][1] , wt = edges[i][2] ; 
            dist[u][v] = wt ; 
            dist[v][u] = wt ; 
        }

        for(int via = 0 ; via < n ; via++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(dist[i][via] != 1e8 && dist[via][j] != 1e8){
                        dist[i][j] = min(dist[i][j] , dist[i][via] + dist[via][j]) ; 
                    }
                }
            }
        }
        int count = INT_MAX ; 
        int ans = -1 ;
        for(int i = 0 ; i < n ; i++){
            int c= 0 ; 
            for(int j = 0 ; j < n ;j++){
                if(distanceThreshold >= dist[i][j]) c++;
            }
            //cout<<i<<" "<<c<<endl;
            if(c <= count){
                count = c;
                ans = i ;
            } 
        }
        return ans ;
        
    }
};