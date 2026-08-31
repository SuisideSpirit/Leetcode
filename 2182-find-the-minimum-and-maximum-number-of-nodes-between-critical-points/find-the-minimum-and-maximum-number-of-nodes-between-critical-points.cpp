class Solution {
public:
    int minD(vector <int> v){
        int mini = INT_MAX ;
        for (int  i= 0 ; i<v.size()-1; i++){
            int m = v[i+1] - v[i] ;
            mini = min(m,mini);
        }
        return mini ;
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector <int> ans ;
        vector <int> crit ; 
        int idx = 1 ; 
        ListNode * a = head ;
        ListNode *b = head->next ;
        ListNode *c = head->next->next ;
        while (c){
            if (a->val > b->val && c->val >b->val) crit.push_back(idx);
            if (a->val < b->val && c->val < b->val) crit.push_back(idx);
            a= a->next ;
            b =b->next ;
            c= c->next;
            idx++ ;
        }
        vector <int> ans2(2,-1);
        if (crit.size() == 0 || crit.size() == 1) return ans2 ;
        if (crit.size() == 2) {
            ans.push_back(crit[1] - crit[0]);
            ans.push_back(crit[1] - crit[0]);
            return ans ;
        }
        int max = crit[crit.size()-1] - crit[0] ;
        int min = minD(crit);
        ans.push_back(min);
        ans.push_back(max) ;

        
        return ans ;
    }
};