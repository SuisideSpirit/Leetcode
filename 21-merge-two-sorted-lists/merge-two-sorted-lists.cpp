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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0) ;
        ListNode* curr = head;  
        while(list1 != NULL && list2 != NULL){
            int num1 = list1->val ; 
            int num2 = list2->val; 
            if(num1 <= num2){
                ListNode* temp = new ListNode(num1) ; 
                head->next = temp ; 
                list1 = list1->next ;
            }
            else {
                ListNode* temp = new ListNode(num2) ; 
                head->next = temp ; 
                list2 = list2->next ;
            }
            head = head->next ; 
        }
        while(list1){
            ListNode* temp = new ListNode(list1->val) ; 
            head->next = temp ; 
            head = head->next ; 
            list1 = list1->next ; 
        }
        while(list2){
            ListNode* temp = new ListNode(list2->val) ; 
            head->next = temp ; 
            head = head->next ; 
            list2 = list2->next ;
        }
        return curr->next ; 
        
    }
};