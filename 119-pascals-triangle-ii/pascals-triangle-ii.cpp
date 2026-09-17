class Solution {
public:
    long long Combination(int n, int r) {
        r = min(r, n - r);
        long long ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
        }
        return ans;
    }
    vector<int> getRow(int r) {
        vector <int> ans ; 
        for(int i = 0 ; i <= r ; i++){
            ans.push_back(Combination(r , i)) ;
        }
        return ans ; 
    }
};