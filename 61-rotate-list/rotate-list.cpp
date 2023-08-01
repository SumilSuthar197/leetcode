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
    int getLength(ListNode* head){
        ListNode* temp=head;
        int i=0;
        while(temp!=nullptr){
            temp=temp->next;
            i++;
        }
        return i;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int i=0,len=getLength(head);
        k=k%len;
        if(k==0) return head;
        ListNode* temp=head;
        while(i<len-k-1){
            temp=temp->next;
            i++;
        }
        ListNode* newHead=temp->next;
        temp->next=NULL;
        ListNode* curr=newHead;
        while(curr->next!=nullptr){
            curr=curr->next;
        }
        curr->next=head;
        return newHead;
        
    }
};