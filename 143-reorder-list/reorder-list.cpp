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
    ListNode* reverseLL(ListNode* head){
			if (!head) return head;
			ListNode* prev=NULL;
	    ListNode* curr=head;
	    ListNode* forward=curr->next;
	    while(curr != NULL){
		    forward=curr->next;
		    curr->next=prev;
		    prev=curr;
		    curr=forward;
	    }
	    return prev;
    }
    void reorderList(ListNode* head) {
			if (!head || !head->next) return;

			//step1: find mid
	    ListNode* slow=head;
	    ListNode* fast=head;

	    while(fast && fast->next){
	    	fast=fast->next->next;
	    	slow=slow->next;
	    }

      // slow node pointing to middle
	    // step2: reverse after slow
	    ListNode* second=reverseLL(slow->next);
	    slow->next=nullptr;

			//step3:merge start and mid alternate
			ListNode* first=head;
			while(second){
				ListNode* temp1=first->next;
				ListNode* temp2=second->next;
				first->next=second;
				second->next=temp1;
				first=temp1;
				second=temp2;
			}
    }
};