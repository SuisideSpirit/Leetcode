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
    ListNode* swapPairs(ListNode* head) {
        ListNode* prev = new ListNode(100) ; 
        ListNode* ans = prev ;
        ListNode* L1 ;
        ListNode* L2 ;
        while(head != NULL){
            L1 = head ; 
            if(head->next == NULL){
                prev->next = head ;
                break ; 
            }
            L2 = head->next; 
            head = L2->next ;
            L2->next = L1 ; 
            L1->next = head ;
            prev->next = L2 ; 
            prev = L1 ; 
        }
        return ans->next ; 
        
    }
};