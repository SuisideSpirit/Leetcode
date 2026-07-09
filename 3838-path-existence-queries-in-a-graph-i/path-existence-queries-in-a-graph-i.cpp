class Solution {
public:
    int find_parent(int curr , vector <int> &parent){
        if(parent[curr] == curr ) return curr ; 
        int temp = parent[curr] ; 
        return parent[curr] = find_parent(temp , parent) ; 
    }
    void Union(int u , int v , vector <int>& parent , vector <int>& size){
        int pu = find_parent(u,parent) ; 
        int pv = find_parent(v,parent) ; 

        if(size[pu] > size[pv]){
            parent[pv] = pu ; 
            size[pu] += size[pv];
        }
        else {
            parent[pu] = pv ; 
            size[pv] += size[pu];
        }
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& q) {
        vector <int> parent(n) ; 
        vector <int> size(n,1) ; 
        for(int i = 0 ; i < n ; i++){
            parent[i] = i ; 
        }
        for(int i = 0 ; i < n-1 ; i++){
            if(nums[i + 1] - nums[i] <= maxDiff) Union(i , i + 1 , parent , size)  ;
        }
        vector <bool> ans ; 
        for(auto ele : q){
            int u = ele[0] , v = ele[1] ; 
            int pu = find_parent(u,parent) ; 
            int pv = find_parent(v,parent) ; 
            if(pu == pv) ans.push_back(true) ;
            else ans.push_back(false) ;
        }
        return ans ; 

        
    }
};