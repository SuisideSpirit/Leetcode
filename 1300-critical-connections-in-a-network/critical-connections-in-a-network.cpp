class Solution {
public:
    int timer = 1 ;
    vector <vector <int>> bridges ;
    void dfs(int curr, int parent ,vector <vector<int>> &edges ,vector <int> &visited ,
    vector <int>& tin, vector <int> &low ){
        visited[curr] = 1 ; 
        tin[curr] = low[curr] = timer;  
        timer++;
        for(auto ele : edges[curr]){
            if(ele == parent) continue; 
            if(visited[ele] == 0){
                dfs(ele, curr, edges , visited,tin , low) ; 
                low[curr] = min(low[curr] , low[ele]) ; 
                if(low[ele] > tin[curr] ) {
                    bridges.push_back({curr,ele}) ; 
                }
            }
            else{
                low[curr] = min(low[curr] , low[ele]) ; 
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector <vector<int>> edges(n) ;
        for(auto ele : connections){
            int u = ele[0] , v = ele[1] ;
            edges[u].push_back(v) ; 
            edges[v].push_back(u) ;
        }
        vector <int> visited(n,0)  ; 
        vector <int> tin(n) ; 
        vector <int> low(n) ; 
        dfs(0,-1,edges,visited,tin,low) ;
        return bridges ;
    }
};