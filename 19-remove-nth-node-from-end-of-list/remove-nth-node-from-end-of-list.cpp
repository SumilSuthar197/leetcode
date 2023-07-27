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
        while(temp != nullptr){
            temp=temp->next;
            i++;
        }
        return i;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=getLength(head);
        if(length==0 || length==1) return nullptr;
        int k=length-n;
        if(k==0) return head->next;
        ListNode* temp=head;
        int i=1;
        while(i<k){
            temp=temp->next;
            i++;
        }
        ListNode* curr=temp->next;
        temp->next=curr->next;
        curr->next=nullptr;
        delete curr;
        return head;
    }
};