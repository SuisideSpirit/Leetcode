class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x = 0 ; 
        int count = 0; 
        for(int i = 0 ; i < nums.size() ; i++){
            if(count == 0 && nums[i] != x ){
                x = nums[i] ;
                count = 1 ; 
            }
            else {
                if(x == nums[i]) count++;
                else count-- ;
            }
        }
         
        return x; 
        
    }
};