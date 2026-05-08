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
    struct compare{
        bool operator ()(ListNode* l1, ListNode* l2){
            return l1->val>l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare>pq;
        for(auto it: lists){
            if(it) pq.push(it);
        }
        ListNode* dummy = new ListNode();
        ListNode* dm = dummy;
        while(!pq.empty()){
            ListNode* smallest = pq.top();
            pq.pop();
            dm->next = smallest;
            dm = dm->next;
            if(smallest->next){
                pq.push(smallest->next);
            }
        }
        return dummy->next;
    }
};