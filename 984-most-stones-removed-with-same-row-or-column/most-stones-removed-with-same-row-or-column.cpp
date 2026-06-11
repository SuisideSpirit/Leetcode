class Solution {
public:
    int find_parent(int curr , vector <int> &parent){
        if(curr == parent[curr]) return curr ;
        int p = parent[curr] ; 
        return parent[curr] = find_parent(p,parent) ;   
    }
    void Union(int u , int v ,vector <int>& parent,vector <int> &size){
        int up = find_parent(u,parent) ; 
        int vp = find_parent(v,parent)  ;
        if(up == vp ) return ; 
        if(size[up] < size[vp]){
            parent[up] = vp ; 
            size[vp] += size[up] ; 
        }
        else {
            parent[vp] = up ; 
            size[up] += size[vp] ; 
        }
        return ; 
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size() ; 
        vector <int> parent(n) ; 
        vector <int> size(n,1) ; 
        for(int i = 0 ; i < n; i++) parent[i] = i ; 
        vector <pair<int,int>> X , Y ; 
        for(int i = 0 ; i < n ;i++){
            X.push_back({stones[i][0],i}) ;
            Y.push_back({stones[i][1],i}) ; 
        }
        sort(X.begin() , X.end()) ; 
        sort(Y.begin() , Y.end()) ; 
        for(int i = 0 ; i < X.size() -1 ; i++){
            int u = X[i].second, v = X[i+1].second ;
            if(X[i].first == X[i+1].first) Union(u,v,parent,size) ;
        }
        for(int i = 0 ; i < X.size() -1 ; i++){
            int u = Y[i].second , v = Y[i+1].second ;
            if(Y[i].first == Y[i+1].first) Union(u,v,parent,size) ;
        }
        unordered_set <int> st; 
        for(int i = 0 ; i < n ; i++){
            int p = find_parent(i,parent) ;
            st.insert(p) ;
        }
        return n - st.size() ;
        
    }
}; 