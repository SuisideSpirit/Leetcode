class Solution {
public:
    vector <vector<int>> dp ;
    int solve(int i , int j ,vector<int>& v1, vector<int>& v2){
        if(i == v1.size() || j == v2.size()) return 0 ; 
        
        if(dp[i][j] != -1 ) return dp[i][j] ; 
        int add = v1[i] * v2[j] ; 
        int move = solve(i+1,j+1,v1, v2) ;
        move += add ; 
        int move1 = solve(i+1,j,v1, v2) ;  
        int move2 = solve(i,j+1,v1, v2) ; 

        int ans = max(move1 , move2) ;
        ans = max(ans, move) ; 

        return dp[i][j] = ans ;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(nums1.size() , vector <int> (nums2.size() , -1)) ; 
        int max1 = INT_MIN , max2 = INT_MIN ; 
        int min1 = INT_MAX , min2 = INT_MAX ; 
        for(int i = 0; i< nums1.size() ; i++){
            max1 = max(max1,nums1[i]) ;
            min1 = min(min1, nums1[i]) ; 
        }
        for(int i = 0; i< nums2.size() ; i++){
            max2 = max(max2,nums2[i]) ; 
            min2 = min(min2,nums2[i]) ; 
        }
        int ans = solve(0,0,nums1,nums2) ;
        if(ans == 0){
            if(max1 <= 0 ) return max1*min2 ;
            else return min1*max2 ; 
        }
        return ans ;
    }
}; 