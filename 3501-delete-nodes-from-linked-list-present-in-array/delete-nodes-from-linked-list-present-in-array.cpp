/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set <int> st ; 
        for(int i = 0 ; i<nums.size() ; i++){
            st.insert(nums[i]);
        }
        ListNode* temp = head ;
        ListNode* start = new ListNode (100);
        ListNode* prev = start ;
        while (temp){
            if (st.find(temp->val) == st.end()){
                prev->next = temp ;
                prev = prev->next ; 
            }
            temp = temp->next; 
        }
        prev->next = NULL ;
        return start->next ; ;
        
    }
};