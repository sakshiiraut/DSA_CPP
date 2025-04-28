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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
         if(len==1) {head=head->next;
        return head;} 
         else if(n==len){head=head->next;
        return head;}
        temp=head;
        int m=len-n;
        // else{
        for(int i=0;i<m-1;i++){
            temp=temp->next;
        }
        temp->next = temp->next->next;
         return head;
    }
};