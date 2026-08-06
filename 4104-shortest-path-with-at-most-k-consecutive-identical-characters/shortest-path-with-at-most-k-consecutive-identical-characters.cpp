class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string label, int k) {
        unordered_map <int,vector <pair<int,int>>> mp ;
        for(auto ele : edges){
            int u = ele[0] , v = ele[1], w = ele[2] ;
            mp[u].push_back({v,w}) ; 
        }
        int ans = -1 ;
        priority_queue <pair<int,pair<int,int>> , vector <pair<int,pair<int,int>>> , 
        greater<pair<int,pair<int,int>>>> pq ; 
        pq.push({0 , { 0 , 1 }}) ; 
        vector <vector <int>> dist(n,vector <int> (k+1 , INT_MAX)) ; 
        dist[0][0] = 0 ; 
        while(pq.size() != 0){
            auto top = pq.top() ; 
            pq.pop() ; 
            int curr = top.second.first, w = top.first , rep = top.second.second ;
            if(curr == n-1) return w ; 
            for(auto ele : mp[curr]){
                int next = ele.first , nw = w + ele.second;
                if(label[curr] != label[next] && dist[next][1] > nw){ 
                    pq.push({nw , {next , 1}}) ; 
                    dist[next][1] = nw ;
                }
                else{
                    if(rep + 1 <= k && dist[next][rep + 1] > nw){
                        pq.push({nw, {next, rep +1}}) ; 
                        dist[next][rep + 1] = nw ;
                    }
                }
            }
        }
        return ans ; 
    }
};