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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return nullptr;
        }

        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast){
            fast=fast->next;
            if(fast==nullptr || fast->next==nullptr) break;
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};