class Solution {
public:
    typedef pair<int,int> pp ;
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size() ;
        if(n == 1 || n== 0 ) return 0 ;
        queue <pair<int,int>> que ; 
        set <pp> visited ; 

        for(int i = 0; i  < n ; i++){
            int mask = (1<<i);
            que.push({i,mask}) ; 
            visited.insert({i,mask}) ;
        }
        int allVisited = (1<<n)-1 ;
        int path = 0 ; 
        while(que.size() != 0 ){
            int size = que.size() ;
            path++;
            while(size--){
                pp curr = que.front() ;
                que.pop() ;
                int currNode = curr.first ;
                int currMask = curr.second ;
                for(int &adj : graph[currNode]){
                    int nextMask = currMask | (1<<adj) ;
                    if(nextMask == allVisited) return path ; 
                    if(visited.find({adj,nextMask}) == visited.end()){
                        visited.insert({adj,nextMask}) ; 
                        que.push({adj,nextMask}) ;
                    }
                }
            }
        }
        return -1 ;
    }
};