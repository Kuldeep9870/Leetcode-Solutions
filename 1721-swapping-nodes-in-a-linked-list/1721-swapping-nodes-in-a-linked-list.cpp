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
    int count(ListNode* root){
        int cnt=0;
        ListNode* temp=root;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int n=count(head);
        n=n-k+1;
        ListNode* kfront;
        ListNode* kback;
        ListNode* temp=head;
        int i=1;
        while(temp!=NULL){
            if(i==k){
                kfront=temp;
            }
            if(i==n){
                kback=temp;
            }
            i++;
            temp=temp->next;
        }
        swap(kfront->val,kback->val);
        return head;
    }
};