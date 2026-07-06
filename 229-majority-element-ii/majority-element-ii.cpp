class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin() ,nums.end()) ; 
        int c = nums.size()/3  ; 
        cout<<c<<endl;
        vector <int> ans ; 
        for(int i = 0 ; i < nums.size() ; i++){
            int st = i ;
            int end = i +1 ;
            while(end != nums.size() && nums[st] == nums[end]){
                end++;
            }
            //cout<<nums[i]<<" "<<st<<" "<<end<<endl ;
            if(end - st > c ) ans.push_back(nums[i]) ; 
            i = end-1 ;
        }
        return ans ; 
        
    }
};