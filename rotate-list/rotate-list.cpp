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
        if(head == NULL || k==0) return head;
        
        int l = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            l++;
            temp = temp->next;
        }
        
        int m = k%l;
        
        if(m==0) return head;
        
        int pos = l - m - 1;
        
        temp = head;
        
        while(temp!=NULL && pos--){
            temp = temp->next;
        }
        
        ListNode* curr = temp->next;
        temp->next = NULL;
        temp = curr;
        
        while(curr->next!=NULL){
            curr = curr->next;
        }
        
        curr->next = head;
        
        return temp;
    }
};