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
        ListNode* listBefore=new ListNode(-1);
        ListNode* listAfter=new ListNode(-1);
        ListNode* beforeTail=listBefore;
        ListNode* afterTail=listAfter;

        while(head){
            if(head->val<x){
                beforeTail->next=head;
                beforeTail=beforeTail->next;
            }
            else{
                afterTail->next=head;
                afterTail=afterTail->next;
            }
            head=head->next;
        }

        beforeTail->next=listAfter->next;
        afterTail->next=nullptr;
        return listBefore->next;
    }
};