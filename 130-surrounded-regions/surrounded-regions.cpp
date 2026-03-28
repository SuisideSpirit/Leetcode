class Solution {
public:
    void solve(vector<vector<char>>& v) {
        int n = v.size() ;
        int m = v[0].size() ;

        vector <vector<bool>> visited(n,vector <bool> (m,false)) ;
        queue <pair<int,int>> q ;
        for(int i = 0 ; i < n ;i++){
            if(v[i][0] == 'O') {
                q.push({i,0}) ;
                visited[i][0] = true;
            }
            if(v[i][m-1] == 'O'){
                q.push({i,m-1}) ;
                visited[i][m-1] = true;
            }
        }
        for(int j = 0 ; j < m ;j++){
            if(v[0][j] == 'O'){
                q.push({0,j}) ;
                visited[0][j] = true;
            }
            if(v[n-1][j] == 'O'){
                q.push({n-1,j}) ;
                visited[n-1][j] = true;
            }
        }

        while(q.size() != 0){
            pair <int,int> p = q.front() ; 
            q.pop() ;
            int i = p.first; 
            int j = p.second ; 
            if(i - 1 >= 0 && visited[i-1][j] == false && v[i-1][j] == 'O'){
                visited[i-1][j] = true ;
                q.push({i-1,j}) ;               
            }
            if(i + 1 < n && visited[i+1][j] == false && v[i+1][j] == 'O'){;
                visited[i+1][j] = true ;
                q.push({i+1,j}) ;               
            }
            if(j - 1 >= 0 && visited[i][j-1] == false && v[i][j-1] == 'O'){
                visited[i][j-1] = true ;
                q.push({i,j-1}) ;               
            }
            if(j+1 < m && visited[i][j+1] == false && v[i][j+1] == 'O'){
                visited[i][j+1] = true ;
                q.push({i,j+1}) ;               
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(visited[i][j]) v[i][j] = 'O' ;
                else v[i][j] = 'X' ;
            }
        }
    }
};