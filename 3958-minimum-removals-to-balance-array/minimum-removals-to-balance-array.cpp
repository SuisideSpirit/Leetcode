class Solution {
public:
    typedef long long ll ;
    int floorIndex(vector<int>& arr, ll k , ll start) {
        int low = start, high = arr.size() - 1;
        int ans = -1;   // in case no element <= k exists

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] <= k) {
                ans = mid;        // valid candidate
                low = mid + 1;    // try to find a bigger one
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end()) ; 
        int n = nums.size() ;
        ll ans= n-1; 
        for(int i = 0 ; i<n ; i++){
            ll temp = i ; 
            int idx = floorIndex(nums,(ll)(nums[i])*(ll)(k),i) ; 
            temp += (n-1-idx) ; 
            ans = min(temp,ans) ;
        }
        return ans ;
    }
}; 