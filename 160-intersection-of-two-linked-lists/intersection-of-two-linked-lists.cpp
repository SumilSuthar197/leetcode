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
    int getLength(ListNode* head){
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=getLength(headA);
        int lenB=getLength(headB);

        int extra=abs(lenA-lenB);
        if(lenA>lenB){
            while(extra--) headA=headA->next;
        }
        else{
            while(extra--) headB=headB->next;
        }

        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }

        return headA;
    }
};