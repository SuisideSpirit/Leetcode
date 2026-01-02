class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() ;
        unordered_map <int,int> mp; 
        for(int i = 0 ;i< n ;i++){
            if(mp[nums[i]] != 0) return nums[i] ; 
            else mp[nums[i]]++;
        }
        return nums[0] ;
    }
};