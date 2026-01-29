
// Leetcode 19: Remove Nth node from end of list
// Approach: Two pointers
// TC and SC : O(N),  O(1)


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        for(int i=0; i<n; i++){
            fast = fast->next;
        }

        if(fast == NULL) return head->next;

        while(fast && fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* delNode= slow->next;
        slow->next = slow->next->next;
        delete(delNode);
        return head;
    }
};
