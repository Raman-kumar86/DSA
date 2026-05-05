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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp1 = head;
        int n = 0;
        while(temp1){
            temp1 = temp1->next;
            n++;
        }
        if(k==0 || head==nullptr) return head;
        k = k%n;
        if(k==0) return head;
        int len = n-k;
        ListNode* temp2 = head;
        for(int i=1;i<len;i++){
            temp2 = temp2->next;
        }
        ListNode* newHead = temp2->next;
        temp2->next = nullptr;
        ListNode* tail = newHead;
        while(tail->next){
            tail = tail->next;
        }
        tail->next = head;
        return newHead;
    }
};