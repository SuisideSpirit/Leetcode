class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector <int> indegree(n,0) ; 
        vector <vector<int>> neighbour(n) ; 
        for(int i = 0 ; i < pre.size() ;i++){
            int from = pre[i][1] ; 
            int to = pre[i][0] ;
            indegree[to]++;
            neighbour[from].push_back(to) ; 
        }
        queue <int> q ;
        for(int i = 0 ; i < n ;i++){
            if(indegree[i] == 0 ) q.push(i) ;
        }
        while(!q.empty()){
            int curr = q.front() ; 
            q.pop() ; 
            for(auto ele : neighbour[curr]){
                indegree[ele]--;
                if(indegree[ele] == 0 )q.push(ele) ;
            }
        }
        for(int i= 0 ; i < n ; i++){
            if(indegree[i] != 0) return false ;
        }
        return true ;
        
        
    }
};