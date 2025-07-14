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
        ListNode* temp=head;
        int size=0;
     while(temp != nullptr){
        temp=temp->next;
        size++;
     }  
     temp=head;
     size=size-1; 
     int number=0;
      while(temp != nullptr){
         number+=(1<<size)*(temp->val);
         temp=temp->next;
         size--;
      }
      return number;
    }
};