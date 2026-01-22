// Leetcode 206 : Reverse the Linked List
// Approach : Recursion
// Time and sppace complexity:  O(N) , O(N)




class Solution {
private:
    void reverse(ListNode* &head, ListNode* curr, ListNode* prev){
        //base case
        if(curr == NULL){
            head = prev;
            return;
        }

        reverse(head, curr->next, curr);
        curr->next = prev;
    }
public:
    ListNode* reverseList(ListNode* head) {
       ListNode* curr = head;
       ListNode* prev = NULL;
       reverse(head, curr, prev);
       return head;
};
};



