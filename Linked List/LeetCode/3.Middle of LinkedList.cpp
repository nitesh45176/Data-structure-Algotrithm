// Leetcode 876 : Middle of the Linked List
// Approach : Two pointers
// Time and sppace complexity:  O(N) , O(1)


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        //edge case
        if(head == NULL ){
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
