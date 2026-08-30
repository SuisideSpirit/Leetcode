class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size() ; 
        vector <int> pre(n, 0) ,suf(n, 0) ; 
        stack <int> st ;
        st.push(nums[0]) ; 
        for(int i = 0 ; i < n ; i++){
            pre[i] = st.top() ; 
            if(st.top() < nums[i]) st.push(nums[i]) ; 
        }
        while(st.size() > 0) st.pop() ; 
        st.push(nums[n-1]) ;
        for(int i = n-2 ; i >= 0 ; i--){
            suf[i] = st.top() ; 
            if(st.top() < nums[i]) st.push(nums[i]) ; 
        }
        int ans = 0 ;
        for(int i =0 ; i < n ; i++){
            ans += max(0 , min(pre[i] , suf[i]) - nums[i] ) ;
        }
        return ans ;
        
    }
};