// Leetcode 234: Check if a Linked List is Palindrome or not
// Approach : Optimal Palindrome Linked List approach
// Time and space complexity: O(N) , O(1)

class Solution {
private:
       ListNode* reverse( ListNode* prev, ListNode* curr){
         
           while(curr != NULL ){
              ListNode* temp = curr->next;
              curr->next = prev;
              prev = curr;
              curr = temp;
           }
           return prev;
       }
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
               slow = slow->next;
               fast = fast->next->next;
        }

        ListNode* newHead = reverse(NULL,slow->next);
        ListNode* first = head;
        ListNode* second = newHead;

        while(second != NULL){
           if(first->val != second->val){
               reverse(NULL,slow->next);
               return false;
            
           } 
        first = first->next;
        second = second->next;
        }
        reverse(NULL,slow->next);
        return true;
    }
};
