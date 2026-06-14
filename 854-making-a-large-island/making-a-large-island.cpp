class Solution {
  public:
    int find_parent(int curr,vector <int>& parents ){
        if(parents[curr] == curr) return curr; 
        int p = parents[curr] ; 
        return parents[curr] = find_parent(p,parents) ; 
    }
    void UnionBySize(int u , int v ,vector <int>& size, vector <int>& parents){
        u = find_parent(u,parents) ; 
        v = find_parent(v,parents) ; 
        if(u == v) return ; 
        if(size[u] >= size[v]){
            size[u] += size[v] ; 
            parents[v] = u ; 
        }
        else{
            size[v] += size[u] ; 
            parents[u] = v ;
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        // code here
        int n = grid.size() ; 
        vector <int> parents(n*n) ; 
        vector <int> size(n*n,1) ; 
        for(int i = 0; i < n*n;i++) parents[i] = i ;
        
        vector<pair<int,int>> moves = {{1,0},{-1,0},{0,1},{0,-1}} ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 0) continue ;
                int curr = n*i + j ; 
                for(auto [dx,dy] : moves){
                    int nx = i + dx ; 
                    int ny = j + dy ; 
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1){
                        int next = nx*n + ny ;
                        UnionBySize(curr,next,size,parents) ;
                    }
                }
            }
        }
        int ans = 0 ; 
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1) continue ;
                unordered_set <int> st ;
                int sum = 0 ; 
                for(auto [dx,dy] : moves){
                    int nx = i + dx ; 
                    int ny = j + dy ; 
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 1){
                        int temp = nx*n + ny ;
                        int p = find_parent(temp,parents) ; 
                        if(st.find(p) == st.end()){
                            st.insert(p) ;
                            sum += size[p] ; 
                        }
                    }
                }
                ans = max(ans ,sum +1 )  ;
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                int curr = n*i + j ;
                ans = max(ans , size[find_parent(curr,parents)]) ; 
            }
        }
        return ans ;
        
        
    }
};