// Leetcode 206 : Reverse the Linked List
// Approach : Recursion
// Time and sppace complexity:  O(N) , O(N)




class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       //Base case
       if(head == NULL || head->next==NULL){
         return head;
       }

       ListNode* newHead = reverseList(head->next);
       ListNode* front = head->next;
       front->next = head;
       head ->next = NULL;
       return newHead;
    }
};

