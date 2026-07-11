class Solution {
public:
    int find_parent(int curr , vector <int> &parent){
        if(parent[curr] == curr) return curr ; 
        int temp = parent[curr] ;
        return parent[curr] = find_parent(temp , parent) ;
    }
    void Union(int u , int v ,vector <int> &size , vector <int>& parent ,vector <int> &edges){
        int pu = find_parent(u , parent) ;
        int pv = find_parent(v , parent) ; 
        if(pu == pv) edges[pu]++;
        else if(size[pu] > size[pv]){
            size[pu] += size[pv] ; 
            edges[pu] += edges[pv] ; 
            edges[pu]++;
            parent[pv] = pu ; 
        }
        else{
            size[pv] += size[pu] ; 
            edges[pv]++;
            edges[pv] += edges[pu] ; 
            parent[pu] = pv ; 
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edge) {
        vector <int> parent(n,0) ; 
        vector <int> edges(n , 0 ) , size(n,1) ;
        for(int i =0 ; i<n ; i++){
            parent[i] = i ;
        }
        for(auto ele : edge){
            int u = ele[0] ; 
            int v = ele[1] ; 
            Union(u,v,size,parent,edges) ; 
        }
        unordered_set <int> st ;
        int ans = 0 ;
        for(int i = 0 ; i < n ; i++){
            int p = find_parent(i,parent) ;
            if(st.find(p) != st.end()) continue ; 
            st.insert(p) ; 
            int e = edges[p] ; 
            int s = size[p]  ;
            cout<<p<<" "<<e<<" "<<s<<endl;
            if(  s*(s-1)/2 == e ){
                ans++; 
                //cout<<p<<endl;
            }
        }
        return ans ;
    }
};