typedef pair<int,int> pp ;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        vector <vector<pp>> edges(n) ; 
        vector <int> dist(n ,1e9) ;
        for(int i = 0 ; i < f.size() ;i++){
            int to = f[i][1] , from= f[i][0] , cost = f[i][2] ; 
            edges[from].push_back({to,cost}) ; 
        }
        queue<pair<int, pair<int,int>>> pq;
        for(auto ele : edges[src]){ 
            pq.push({0,{ele.first,ele.second}}) ; 
        }
        int ans = INT_MAX ;
        while(pq.size() != 0 ){
            auto ele = pq.front() ; 
            pq.pop() ; 
            int steps = ele.first ,curr = ele.second.first , cost = ele.second.second ; 
            if(curr == dst){
                ans = min(ans,cost) ;
            }
            dist[curr] = min(dist[curr] , cost) ;
            steps++; 
            if(steps > k ) continue ;
            for(auto e : edges[curr]){
                if(steps <= k && cost + e.second < dist[e.first]) pq.push({steps,{e.first,e.second + cost}}) ; 
            }
        }
        if(ans == INT_MAX) return -1 ;
        return ans ; 
    }
};