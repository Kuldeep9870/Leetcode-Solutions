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
    int getDecimalValue(ListNode* head) {
        vector<int> value;
        while(head!=NULL){
            value.insert(value.begin(),head->val);
            head=head->next;
        }
        int two=1;
        int ans=0;
        for(int i=0;i<value.size();i++){
            ans=ans+value[i]*two;
            two=two*2;
        }
        return ans;
    }
};