class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector <vector<pair<int,int>>> edges(n+1) ;
        for(int i = 0; i <times.size() ;i++){
            int from = times[i][0] ; 
            int to = times[i][1] ; 
            int w = times[i][2] ; 
            edges[from].push_back({to,w}) ;
        }
        vector <int> v(n+1,INT_MAX) ;
        queue <pair<int,int>> q ; 
        q.push({k,0}) ; 
        while(q.size() != 0 ){
            pair <int,int> p = q.front() ; 
            int curr = p.first ;  
            int time = p.second ;
            q.pop() ;
            if(v[curr] < time) continue ;
            v[curr] = time;
            for(auto ele : edges[curr]){
                if(v[ele.first] > time + ele.second) q.push({ele.first , time + ele.second}) ;
            }
        }
        int maxi = 0 ; 
        for(int i = 1 ; i < n+1 ; i++){
            if(v[i] == INT_MAX) return -1 ;
            maxi = max(maxi,v[i]) ;
        }
        return maxi ;
    }
};