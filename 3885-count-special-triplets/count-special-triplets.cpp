class Solution {
public:

    int specialTriplets(vector<int>& nums) {
        long long n = nums.size() ;
        long long mod =1000000007;
        unordered_map <long long,long long> Next , Prev ;
        for(int i =0 ;i<n ;i++){
            Next[nums[i]]++;
        }
        long long ans = 0 ;
        Prev[nums[0]]++;
        Next[nums[0]]--;
        for(int i =1 ;i<n-1;i++){
            Next[nums[i]]--;
            if(Prev[nums[i]*2] != 0 && Next[nums[i]*2] != 0){
                ans = (ans%mod + (Prev[nums[i]*2])*(Next[nums[i]*2])%mod)%mod ;
            }
            Prev[nums[i]]++;
        }
        return ans ; 
        
    }
};