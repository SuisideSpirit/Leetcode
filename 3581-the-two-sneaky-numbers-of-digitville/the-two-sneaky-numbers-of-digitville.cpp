class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size() ; 

        unordered_map <int,int> mp;
        for(int i =0 ; i<n ; i++){
            mp[nums[i]]++;
        }
        vector <int> ans ; 
        for(auto ele :mp){
            if(ele.first >= n-2 ) ans.push_back(ele.first) ; 
            if(ele.second == 2 ) ans.push_back(ele.first) ; 
            if(ele.second == 3 ){
                ans.push_back(ele.first) ; 
                ans.push_back(ele.first) ; 
            }
        }

        return ans ;
    }
};