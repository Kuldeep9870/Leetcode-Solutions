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
    ListNode* partition(ListNode* head, int x) {
        ListNode* first=new ListNode(-1);
        ListNode* second=new ListNode(-1);
        
        ListNode* temp1=first,*temp2=second;
        
        ListNode* temp=head;
        
        while(temp!=NULL){
            if(temp->val<x){
                temp1->next=temp;
                temp1=temp1->next;
            }
            else{
                temp2->next=temp;
                temp2=temp2->next;
            }
            temp=temp->next;
        }
        //join two partition
        temp1->next=second->next;
        temp2->next=NULL;
        return first->next;
    }
};