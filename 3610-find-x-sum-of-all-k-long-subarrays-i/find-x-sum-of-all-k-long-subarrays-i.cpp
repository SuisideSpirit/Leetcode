class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector <int> a ;
        int n = nums.size() ;

        unordered_map <int,int> mp ;
        
        for(int i =0; i<k-1 ;i++){
            mp[nums[i]]++;
        }

        for(int i = 0 ; i<n-k+1; i++){
            mp[nums[i+k-1]]++;
            priority_queue<pair<int,int>> pq;
            int ans = 0 ;
            for(auto ele :mp){
                pq.push({ele.second,ele.first}) ;
            }
            for(int i = 0; i<x;i++){
                pair <int,int> p = pq.top() ;
                cout<<p.first<<" "<<p.second<<endl;
                ans += (p.first*p.second) ; 
                pq.pop() ;
                if(pq.size() == 0 ) break ;
            }
            mp[nums[i]]--;
            a.push_back(ans);
        }
        return a ;
        
    }
};