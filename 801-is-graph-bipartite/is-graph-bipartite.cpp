class Solution {
public:
    bool dfs(int curr ,int color ,vector <int> &v , vector<vector<int>>& graph){
        //cout<<curr<<" "<<color<<endl;
        if(v[curr] != -1 && color == v[curr]) return true ;
        if(v[curr] != -1 && color != v[curr]) return false ;

        v[curr] = color ;
        for(auto ele : graph[curr]){
            bool res = dfs(ele , 1 - color , v , graph) ; 
            if(!res)return res ;
        }
        return true ;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size() ;
        vector <int> v(n,-1) ; 
        
        if(!dfs(0,0,v,graph)) return false ;
        for(int i = 0; i < n ;i++){
            if(v[i] == -1){
                if(!dfs(i,0,v,graph)) return false ;
            }
        }
        return true ;
        
    }
};