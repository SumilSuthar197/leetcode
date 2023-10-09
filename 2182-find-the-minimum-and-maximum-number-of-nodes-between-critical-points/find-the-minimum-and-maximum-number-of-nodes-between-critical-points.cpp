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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v;
        ListNode* prev=head;
        head=head->next;
        int i=2;
        while(head->next){
            if((prev->val>head->val && head->val<head->next->val)||(prev->val<head->val && head->val>head->next->val)){
                v.push_back(i);
            }
            prev=head;
            head=head->next;
            i++;
        }

        if(v.size()<2) return {-1,-1};
        int minD=INT_MAX;
        int maxD=v.back()-v.front();
        for(int i=1;i<v.size();i++){
            minD=min(minD,v[i]-v[i-1]);
        }
        return {minD,maxD};
    }
};