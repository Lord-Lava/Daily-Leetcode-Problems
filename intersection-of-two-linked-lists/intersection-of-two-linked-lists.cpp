/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        
        int cnt1=0,cnt2=0;
        
        while(temp1!=NULL){
            cnt1++;
            temp1 = temp1->next;
        }
        while(temp2!=NULL){
            cnt2++;
            temp2 = temp2->next;
        }
        
        if(cnt1>cnt2){
            cnt1-=cnt2;
            while(cnt1--){
                headA = headA->next;
            }
        }
        else if(cnt2>cnt1){
            cnt2-=cnt1;
            while(cnt2--){
                headB = headB->next;
            }
        }
        
        while(headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
    }
};