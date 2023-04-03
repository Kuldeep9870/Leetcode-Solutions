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
    int pairSum(ListNode* head) {
        map<int,int> NodeMap;
        ListNode* temp=head;
        int n=0;
        while(temp!=NULL){
            NodeMap[n]=temp->val;
            temp=temp->next;
            n++;
        }
        int maxSum=INT_MIN;
        int sum=0;
        for(int i=0;i<n/2;i++){
            sum=NodeMap[i]+NodeMap[n-1-i];
            
            maxSum=max(sum,maxSum);
        }
        return maxSum;
    }
};