class Solution {
public:
    vector <vector<int>> ans ;
    void solve(int idx,vector <int>& path, vector<vector<int>>& graph, vector <int> visited){
        if(idx == graph.size() -1 ){
            ans.push_back(path) ;
            return ;
        }
        if(visited[idx] ==1 ) return ;
        visited[idx] = 1 ;
        for(int i = 0 ;i < graph[idx].size() ; i++){
            vector <int> temp = path ;
            temp.push_back(graph[idx][i]) ;
            solve(graph[idx][i] , temp,graph,visited) ;
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size() ; 
        vector <int> visited(n,0) ;
        vector <int> path = {0};
        solve(0,path , graph , visited) ;
        return ans;
    } 
};