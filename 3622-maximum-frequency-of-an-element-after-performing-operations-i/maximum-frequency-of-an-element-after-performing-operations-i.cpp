class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxEle = *max_element(begin(nums),end(nums)) + k ;

        vector <int> v(maxEle + 1, 0 ) ;
        for(int i = 0 ; i<nums.size() ; i++){
            v[nums[i]]++ ; 
        }
        for(int i = 1 ; i<v.size() ; i++){
            v[i] += v[i-1] ; 
        }

        int res = 0 ;
        for(int target = 0; target <=maxEle ; target++){
            if(v[target] == 0) continue ;

            int leftNum = max(0,target - k);
            int rightNum = min(maxEle,target + k) ;

            int totalCount = v[rightNum] - (leftNum > 0 ? v[leftNum-1] : 0) ;

            int targetCount = v[target] - (target > 0 ? v[target-1] : 0) ;

            int needConversion = totalCount - targetCount ; 

            int maxFreq = targetCount + min(needConversion , numOperations)  ;
            res = max(res ,maxFreq);
        }


        return res ;
    }
};