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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        if(list1==NULL && list2==NULL)
            return NULL;
        ListNode* head=new ListNode(-1);
        ListNode* temp=head;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                temp->next=list1;
                temp=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
        }
        while(list1!=NULL){
            temp->next=list1;
            temp=list1;
                list1=list1->next;
        }
        while(list2!=NULL){
            temp->next=list2;
            temp=list2;
                list2=list2->next;
        }
        return head->next;
        
    }
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode*  res=NULL;
        ListNode* temp=NULL;
        
        while(head!=NULL){
            temp=head;
            head=head->next;
            temp->next=NULL;
            res=mergeTwoLists(res,temp);
        }
        return res;
        
    }
};