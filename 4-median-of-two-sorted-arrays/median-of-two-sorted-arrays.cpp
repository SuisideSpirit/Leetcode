class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0 ; 
        int j = 0 ; 
        int n = nums1.size() ; 
        int m = nums2.size() ; 
        // n + m is odd 3 => 1
        int idx = 0 ; 
        double ans = 0 ; 
        int curr = -1 ; 
        while(i < n &&  j < m ){
            if(i < nums1.size() && j < nums2.size() && nums1[i] > nums2[j]){
                curr = nums2[j] ;
                j++;
                idx++ ; 
            }
            else{
                curr = nums1[i] ; 
                i++;
                idx++ ; 
            }
            if(idx == (n + m)/2 + 1 && (n+m)%2 != 0 ){
                ans += curr ;
            }
            if(idx == (n + m)/2 + 1 && (n+m)%2 == 0 ){
                ans += curr ;
            }
            if(idx == (n + m)/2 && (n+m)%2 == 0 ){
                ans += curr ;
            }
        }
        while(i < n){
            curr = nums1[i] ; 
            i++;
            idx++ ; 
            if(idx == (n + m)/2 + 1 && (n+m)%2 != 0 ){
                ans += curr ;
            }
            if(idx == (n + m)/2 + 1 && (n+m)%2 == 0 ){
                ans += curr ;
            }
            if(idx == (n + m)/2 && (n+m)%2 == 0 ){
                ans += curr ;
            }
        }
        while(j < m){
            curr = nums2[j] ; 
            j++;
            idx++ ; 
            if(idx == (n + m)/2 + 1 && (n+m)%2 != 0 ){
                ans += curr ;
            }
            if(idx == (n + m)/2 + 1 && (n+m)%2 == 0 ){
                ans += curr ;
            }
            if(idx == (n + m)/2 && (n+m)%2 == 0 ){
                ans += curr ;
            }
        }
        if((n + m)%2 == 0){
            cout<<ans;
            ans = ans*1/2.0;
        }
        return ans ; 
    }
};