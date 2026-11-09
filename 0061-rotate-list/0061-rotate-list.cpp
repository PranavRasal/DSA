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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0){
            return head ;
        }
        int count = 0 ;
        ListNode* temp = head ;
        while(temp != NULL){
            count++ ; 
            temp = temp->next ;
        }
         k = k % count ;
         if(k == 0){
            return head ;
         }
        int pos = count - k ;
        temp = head ;
        int i = 1 ;
        while(i < pos){
            temp = temp->next ;
            i++ ;
        }
        ListNode* newHead = temp->next ;
        temp->next = NULL ;
        ListNode* last = newHead ;
        while(newHead->next != NULL){
            newHead = newHead->next ;
        }
        newHead->next = head ;

        
        return last ;
    }
};