/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev;
        ListNode* curr=node;
        while(curr->next!=NULL){
            prev=curr;
            curr=curr->next;
            prev->val=curr->val;
        }
        prev->next=NULL;
    }
};