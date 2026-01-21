class Solution {
public:
    int solve(int n){
        int mult = 1 ;
        while( (n & mult) != 0 ){
            mult *= 2;
        }
        cout<<mult<<endl;
        return n - mult/2 ;
        
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size() ; 
        vector <int> ans(n,-1) ; 
        for(int i = 0 ; i< n ;i++){
            if(nums[i]%2 != 0 ) ans[i] = solve(nums[i]) ; 
        }
        return ans ; 
    }
};