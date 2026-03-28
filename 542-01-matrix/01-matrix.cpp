class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size() ; 
        int m = mat[0].size() ;
        vector <vector <bool>> visited(n,vector <bool> (m,false)) ; 
        vector <vector<int>> distance(n,vector <int> (m,0)) ;
        queue <pair<int,int>> q ;
        for(int i = 0 ; i< n ; i++){
            for (int j = 0 ;j<m ; j++){
                if(mat[i][j] == 0){
                    q.push({i,j}) ;
                    distance[i][j] = 0; 
                    visited[i][j] = true ;
                }
            }
        }
        while(!q.empty()){
            pair <int,int> p = q.front() ; 
            q.pop() ;
            int i = p.first; 
            int j = p.second ; 
            int dis = distance[i][j] ; 
            if(i - 1 >= 0 && visited[i-1][j] == false){
                distance[i-1][j] = dis + 1 ;
                visited[i-1][j] = true ;
                q.push({i-1,j}) ;               
            }
            if(i + 1 < n && visited[i+1][j] == false){
                distance[i+1][j] = dis + 1 ;
                visited[i+1][j] = true ;
                q.push({i+1,j}) ;               
            }
            if(j - 1 >= 0 && visited[i][j-1] == false){
                distance[i][j-1] = dis + 1 ;
                visited[i][j-1] = true ;
                q.push({i,j-1}) ;               
            }
            if(j+1 < m && visited[i][j+1] == false){
                distance[i][j+1] = dis + 1 ;
                visited[i][j+1] = true ;
                q.push({i,j+1}) ;               
            }
        }
        return distance;        
    }
};