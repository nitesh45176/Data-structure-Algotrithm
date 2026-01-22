// Leetcode 206 : Reverse the Linked List
// Approach : Traversing
// Time and sppace complexity:  O(N) , O(1)



class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr =temp;
        }
        return prev;
    }
};


