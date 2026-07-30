class Solution {
public:
    int findGreater(int n , map <int,int> mp ){
        for(auto ele : mp){
            if(ele.first > n) return ele.second ; 
        }
        return -1 ;
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() ;
        bool flag = false;
        map <int,int> mp ;
        for(int i = n-1 ; i >= 0 ; i--){
            int find = findGreater(nums[i] , mp) ; 
            if(find == -1){
                if(mp.find(nums[i]) == mp.end()) mp[nums[i]] = i ; 
            }
            else {
                swap(nums[i] , nums[find]);
                int idx = i +1 ;
                for(int j =0 ; j < (n - i - 1)/2 ; j++){
                    swap(nums[idx] , nums[n-1 - (idx - i -1)]) ; 
                    idx++ ;
                }
                flag = true ;
                break ;
            }
        }
        if(!flag){
            cout<<2<<endl ;
            for(int i = 0 ; i < n/2 ; i++){
                swap(nums[i] , nums[n - 1 - i]) ;
            }
        }
    }
};