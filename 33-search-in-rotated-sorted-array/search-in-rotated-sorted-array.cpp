class Solution {
public:
    int search(vector<int>& v, int target) {
        int n = v.size() ; 
        int high = n-1 ; 
        int low = 0 ;
        while(low <= high){
            int mid = (high + low)/2 ; 
            if(target == v[mid]) return mid ;
            if(v[mid] < v[high] ){
                if(target >= v[mid] && target <= v[high]) low = mid+1 ;
                else high = mid -1;
            }
            else{
                if(target >= v[low] && target <= v[mid]) high = mid-1 ;
                else low = mid + 1;
            }
        }
        return -1;
        
    }
};