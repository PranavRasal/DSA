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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL){
            return head ;
        }
       ListNode* smallHead = new ListNode(0); ;
       ListNode* largeHead = new ListNode(0); ;
       ListNode* smallTemp = smallHead ;
       ListNode* largeTemp = largeHead ;
       while(head != NULL){
            if(head->val < x){
                smallTemp->next = head ;
                head = head->next ;
                smallTemp = smallTemp->next ;
            }else{
                largeTemp->next = head ;
                head = head->next ;
                largeTemp = largeTemp->next ;
            }
       }
       largeTemp->next = NULL ;
       smallTemp->next = largeHead->next ;
       return smallHead->next ;
    }
};