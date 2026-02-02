class Solution {
public:
    typedef pair<long long,long long> pp ;
    typedef long long ll ;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        ll n = nums.size() ; 
        set <pp> KMinimum ; 
        set <pp> remaining ; 
        int i = 1 ;
        ll sum = 0 ;
        while(i - dist < 1){
            KMinimum.insert({nums[i],i}) ;
            sum += nums[i] ; 
            if(KMinimum.size() > k-1){
                pp temp = *KMinimum.rbegin()  ;
                sum -= temp.first ; 
                remaining.insert(temp) ; 
                KMinimum.erase(temp) ; 
            }
            i++;
        }
        ll ans = LONG_MAX ; 
        while(i < n){
            KMinimum.insert({nums[i],i}) ;
            sum += nums[i] ; 

            if(KMinimum.size() > k-1){
                pp temp = *KMinimum.rbegin()  ;
                sum -= temp.first ; 
                remaining.insert(temp) ; 
                KMinimum.erase(temp) ; 
            }
            ans = min(ans,sum) ;
            pp remove = {nums[i - dist], i - dist};

            if (KMinimum.count(remove)) {
                KMinimum.erase(remove);
                sum -= remove.first;

                if (!remaining.empty()) {
                    pp temp = *remaining.begin();
                    KMinimum.insert(temp);
                    sum += temp.first;
                    remaining.erase(temp);
                }
            } else {
                remaining.erase(remove);
            }


            i++;


        }
        return ans+ nums[0];
    }
};