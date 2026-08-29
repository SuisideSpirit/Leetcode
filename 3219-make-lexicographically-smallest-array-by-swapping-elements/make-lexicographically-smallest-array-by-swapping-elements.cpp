class Solution {
public:
    int find_parent(int n , vector<int>& parent){
        if(parent[n] == n) return n ; 
        int temp = find_parent(parent[n] , parent) ; 
        return parent[n] = temp ; 
    }
    void Union(int u , int v , vector <int> &parent , vector <int> &size){
        int pu = find_parent(u , parent) ;
        int pv = find_parent(v , parent) ; 
        if(size[pu] > size[pv]){
            size[pu] += size[pv] ; 
            parent[pv] = pu ;
        }
        else {
            size[pv] += size[pu] ; 
            parent[pu] = pv; 
        }
    }
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size() ; 
        vector <int> parent(n) , size(n, 0 );
        for(int i = 0 ; i < n ; i++) parent[i] = i ; 
        unordered_map<int,priority_queue <int,vector<int>,greater<int>>> mp ;
        vector <pair<int,int>> v ; 
        for(int i = 0 ; i < n ; i++) v.push_back({nums[i] , i}) ; 
        sort(v.begin()  ,v.end()) ; 
        for(int i = 0 ; i < n-1 ; i++){
            if(v[i+1].first - v[i].first <= limit){
                Union(v[i+1].second  , v[i].second , parent , size) ; 
            }
        }
        for(int i = 0 ; i < n ; i++){
            mp[parent[i]].push(nums[i]) ;
        }
        vector<int> ans(n) ; 
        for(int i = 0 ;i < n ; i++){
            int color = parent[i] ; 
            int x = mp[color].top() ;
            mp[color].pop() ; 
            ans[i] = x; 
        }
        return ans ;

        
    }
};