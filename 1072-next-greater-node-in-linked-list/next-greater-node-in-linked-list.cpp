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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head=head->next;
        }

        stack<int> s;
        vector<int> ans(v.size(),0);
        for(int i=0;i<v.size();i++){
            if(!s.empty() && v[i]>v[s.top()]){
                //got a greater element
                int max=i;
                while(!s.empty() && v[i]>v[s.top()]){
                    //pop all smaller element
                    ans[s.top()]=v[max];
                    s.pop();
                }
                s.push(max);
            }
            else{
                //array is decreasing
                s.push(i);
            }
        }
        return ans;
    }
};