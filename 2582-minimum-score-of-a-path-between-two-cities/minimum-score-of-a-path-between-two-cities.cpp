class Solution {
public:
    int Traversal(vector<vector<pair<int,int>>>& edges , int check){
        int n = edges.size() ; 
        priority_queue <pair<int,int> , vector <pair<int,int>> , greater<pair<int,int>>> pq ;
        vector <int> visited(n+1,INT_MAX) ;  
        pq.push({INT_MAX,1}) ; 
        visited[1] =  0  ; 
        while(pq.size() != 0){
            auto x = pq.top() ;
            int curr = x.second, W = x.first;  
            pq.pop() ; 
            if(curr == n && W <= check ){
                cout<<W<<endl;
                return true;
            }
            for(auto ele : edges[curr]){
                int w = ele.second , v = ele.first ; 
                if( visited[v] > min(w,W) ){
                    visited[v] = min(w,W) ; 
                    pq.push({min(w,W),v}) ; 
                }
            }
        }
        return false ;
    }
    int traversal(int curr ,vector<vector<pair<int,int>>>& edges ,vector <int> &visited){
        if(visited[curr] == 1) return INT_MAX ; 
        visited[curr] = 1 ;
        int ans = INT_MAX ; 
        for(auto ele : edges[curr]){
            int w = ele.second , v = ele.first ; 
            ans = min(ans ,w ) ; 
            ans = min(ans , traversal(v,edges , visited)) ; 
        }
        return ans ;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector <vector<pair<int,int>>> edges(n+1) ; 
        for(auto ele : roads){
            int u = ele[0] , v = ele[1] , w = ele[2] ; 
            edges[u].push_back({v,w}) ; 
            edges[v].push_back({u,w}) ; 
        }
        int ans = INT_MAX ;
        vector <int> visited(n+1,0) ; 
        // int low = 0 , high = 10000 ; 
        // while(low <= high){
        //     int mid = low + (high - low) / 2;
        //     if(Traversal(edges,mid)){
        //         ans = mid ; 
        //         high = mid - 1 ;
        //     }
        //     else low = mid + 1 ;
        // }
        return traversal(1,edges,visited) ;
        
    }
};