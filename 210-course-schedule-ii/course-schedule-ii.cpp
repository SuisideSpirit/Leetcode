class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector <int> indegree(n,0) ; 
        vector <vector<int>> neighbour(n) ; 
        for(int i = 0 ; i < pre.size() ;i++){
            int from = pre[i][1] ; 
            int to = pre[i][0] ;
            indegree[to]++;
            neighbour[from].push_back(to) ; 
        }
        unordered_set <int> visited;
        queue <int> q ;
        for(int i = 0 ; i < n ;i++){
            if(indegree[i] == 0 ){
                q.push(i) ;
            }
        } 
        vector <int> ans ; 
        while(!q.empty()){
            int curr = q.front() ;
            q.pop() ; 
            visited.insert(curr) ; 
            ans.push_back(curr) ; 
            if(visited.size() == n){
                break ;
            }
            for(auto ele : neighbour[curr]){
                indegree[ele]--;
                if(indegree[ele] == 0 ){
                    q.push({ele}) ;
                }
            }
        }
        vector <int> v ; 
        if(visited.size() != n) return v ; 
        return ans ;
    }
}; 