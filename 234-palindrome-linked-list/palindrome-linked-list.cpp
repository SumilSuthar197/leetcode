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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        if(!head->next->next){
            if(head->val==head->next->val) return true;
            else return false;
        }

        //finding mid
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        slow=reverseLL(slow);
        //comparing element from start and mid
        while(slow){
            if(head->val!=slow->val) return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
};